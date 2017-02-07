<?php
/**
 * @file
 * User account migration.
 */

/**
 * User migration.
 */
class GhelUserMigration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('GHEL legacy user import');

    // The example uses a SQL database as source.
    // @@@ The db name is hardcoded to bdragon's env atm.
    $query = db_select('funnymonkey_import.member', 'm')
      ->fields('m', array(
        'memberid',
        'password',
        'firstname',
        'lastname',
        'email',
        'statusid',
        'createdate',
        'lastlogin',
        'sex',
        'getmail',
        'occupation',
        'countryid'
    ));
    $this->source = new MigrateSourceSQL($query);
    // Migrate into users.
    $this->destination = new MigrateDestinationUser();

    // We instantiate the MigrateMap.
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'memberid' => array(
            'type' => 'int',
            'unsigned' => TRUE,
            'not null' => TRUE,
          ),
        ),
        MigrateDestinationUser::getKeySchema()
      );

    // Finally we add simple field mappings.
    // 'Username' is unused.
    $this->addFieldMapping('name', 'email')
      ->dedupe('users', 'name');

    $this->addFieldMapping('pass', 'password');
    $this->addFieldMapping('mail', 'email');
    $this->addFieldMapping('field_ghel_first_name', 'firstname');
    $this->addFieldMapping('field_ghel_last_name', 'lastname');

    $roles = user_roles();
    $flipped = array_flip($roles);
    $this->addFieldMapping('roles')
         ->defaultValue(array(DRUPAL_AUTHENTICATED_RID, $flipped['learner']));

    $this->addFieldMapping('field_ghel_sex', 'sex')
      ->callbacks(array($this, 'mapSexField'));
    $this->addFieldMapping('field_ghel_occupation_category', 'occupation')
      ->callbacks(array($this, 'mapOccupationCategory'));
    $this->addFieldMapping('field_ghel_occupation_category:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_ghel_occupation_category:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_ghel_user_location', 'countryid')
      ->callbacks(array($this, 'mapCountry'));
    $this->addFieldMapping('field_ghel_email_notfication', 'getmail');

    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('created', 'createdate');
    $this->addFieldMapping('login', 'lastlogin');
  }

  public function prepare(stdClass $account, stdClass $row) {
    // We need to convert to unix time for these.
    $account->created = strtotime($account->created);
    $account->login = strtotime($account->login);
  }

  /**
   * Map callback for sex.
   */
  public function mapSexField($value) {
    switch ($value) {
      case 'male':
        return 'male';
      case 'female':
        return 'female';
      default:
        return '_none';
    }
  }

  /**
   * Map callback for Organization Category.
   */
  public function mapOrganizationCategory($value) {
    static $terms = array();
    if (empty($terms)) {
      $vocab = taxonomy_vocabulary_machine_name_load('ghel_organization_category');
      $tree = taxonomy_get_tree($vocab->vid);
      foreach ($tree as $term) {
        $terms[$term->name] = $term->tid;
      }
    }

    if (isset($terms[$value])) {
      return $terms[$value];
    }

  }

  /**
   * Map callback for Occupation Category.
   */
  public function mapOccupationCategory($value) {
    static $terms = array();
    if (empty($terms)) {
      $vocab = taxonomy_vocabulary_machine_name_load('ghel_occupation_category');
      $tree = taxonomy_get_tree($vocab->vid);
      foreach ($tree as $term) {
        $terms[$term->name] = $term->tid;
      }
    }

    if (isset($terms[$value])) {
      return $terms[$value];
    }
    return $terms['Other'];
  }

  /**
   * Map callback for country.
   */
  public function mapCountry($value) {
    $countrymap = array(
      '8' => '000',      //""
      '241' => '000',    //""
      '245' => '000',    //""
      '3' => '004',    //"Afghanistan"
      '6' => '008',    //"Albania"
      '58' => '012',   //"Algeria"
      '12' => '016',   //"American Samoa"
      '1' => '020',    //"Andorra"
      '9' => '024',    //"Angola"
      '5' => '660',    //"Anguilla"
      '10' => '010',   //"Antarctica"
      '4' => '028',    //"Antigua & Barbuda"
      '11' => '032',   //"Argentina"
      '7' => '051',    //"Armenia"
      '15' => '533',   //"Aruba"
      '14' => '036',   //"Australia"
      '13' => '040',   //"Austria"
      '16' => '031',   //"Azerbaijan"
      '30' => '044',   //"Bahama"
      '23' => '048',   //"Bahrain"
      '19' => '050',   //"Bangladesh"
      '18' => '052',   //"Barbados"
      '34' => '112',   //"Belarus"
      '20' => '056',   //"Belgium"
      '35' => '084',   //"Belize"
      '25' => '204',   //"Benin"
      '26' => '060',   //"Bermuda"
      '31' => '064',   //"Bhutan"
      '28' => '068',   //"Bolivia"
      '17' => '070',   //"Bosnia And Herzegovina"
      '33' => '072',   //"Botswana"
      '32' => '074',   //"Bouvet Island"
      '29' => '076',   //"Brazil"
      '101' => '086',  //"British Indian Ocean Territory"
      '226' => '092',  //"British Virgin Islands"
      '27' => '096',   //"Brunei Darussalam"
      '22' => '100',   //"Bulgaria"
      '21' => '854',   //"Burkina Faso"
      '24' => '108',   //"Burundi"
      '111' => '116',  //"Cambodia"
      '44' => '120',   //"Cameroon"
      '36' => '124',   //"Canada"
      '49' => '132',   //"Cape Verde"
      '118' => '136',  //"Cayman Islands"
      '41' => '384',   //"Côte D',Ivoire (Ivory Coast)"
      '38' => '140',   //"Central African Republic"
      '202' => '148',  //"Chad"
      '43' => '152',   //"Chile"
      '45' => '156',   //"China"
      '50' => '162',   //"Christmas Island"
      '37' => '166',   //"Cocos (Keeling) Islands"
      '46' => '170',   //"Colombia"
      '113' => '174',  //"Comoros"
      '39' => '178',   //"Congo (DRC)"
      '42' => '184',   //"Cook Iislands"
      '47' => '188',   //"Costa Rica"
      '94' => '191',   //"Croatia"
      '48' => '192',   //"Cuba"
      '51' => '196',   //"Cyprus"
      '52' => '214',   //"Czech Republic"
      '55' => '208',   //"Denmark"
      '54' => '262',   //"Djibouti"
      '56' => '212',   //"Dominica"
      '57' => '214',   //"Dominican Republic"
      '59' => '218',   //"Ecuador"
      '61' => '818',   //"Egypt"
      '198' => '222',  //"El Salvador"
      '84' => '226',   //"Equatorial Guinea"
      '63' => '232',   //"Eritrea"
      '60' => '233',   //"Estonia"
      '65' => '231',   //"Ethiopia"
      '68' => '238',   //"Falkland Islands (Malvinas)"
      '70' => '234',   //"Faroe Islands"
      '67' => '242',   //"Fiji"
      '66' => '246',   //"Finland"
      '71' => '250',   //"France"
      '72' => '250',   //"France, Metropolitan"
      '77' => '254',   //"French Guiana"
      '166' => '258',  //"French Polynesia"
      '203' => '260',  //"French Southern Territories"
      '73' => '266',   //"Gabon"
      '81' => '270',   //"Gambia"
      '76' => '268',   //"Georgia"
      '53' => '276',   //"Germany"
      '78' => '288',   //"Ghana"
      '79' => '292',   //"Gibraltar"
      '85' => '300',   //"Greece"
      '80' => '304',   //"Greenland"
      '75' => '308',   //"Grenada"
      '83' => '312',   //"Guadeloupe"
      '88' => '316',   //"Guam"
      '87' => '320',   //"Guatemala"
      '82' => '324',   //"Guinea"
      '89' => '624',   //"Guinea-Bissau"
      '90' => '328',   //"Guyana"
      '95' => '332',   //"Haiti"
      '92' => '334',   //"Heard & McDonald Islands"
      '93' => '340',   //"Honduras"
      '91' => '344',   //"Hong Kong"
      '96' => '348',   //"Hungary (RCS)"
      '104' => '352',  //"Iceland"
      '100' => '356',  //"India"
      '97' => '360',   //"Indonesia"
      '102' => '368',  //"Iraq"
      '98' => '372',   //"Ireland"
      '103' => '364',  //"Islamic Republic Of Iran"
      '99' => '376',   //"Israel"
      '105' => '380',  //"Italy"
      '106' => '388',  //"Jamaica"
      '108' => '392',  //"Japan"
      '107' => '400',  //"Jordan"
      '119' => '398',  //"Kazakhstan (CAR)"
      '109' => '404',  //"Kenya"
      '112' => '296',  //"Kiribati"
      '115' => '408',  //"Korea, Democratic People',s Republic Of"
      '116' => '410',  //"Korea, Republic Of"
      '117' => '414',  //"Kuwait"
      '110' => '417',  //"Kyrgyzstan (CAR)"
      '120' => '418',  //"Lao People',s Democratic Republic"
      '129' => '428',  //"Latvia"
      '121' => '422',  //"Lebanon"
      '126' => '426',  //"Lesotho"
      '125' => '430',  //"Liberia"
      '130' => '434',  //"Libyan Arab Jamahiriya"
      '123' => '438',  //"Liechtenstein"
      '127' => '440',  //"Lithuania"
      '128' => '442',  //"Luxembourg"
      '139' => '446',  //"MacAu"
      '134' => '450',  //"Madagascar"
      '147' => '454',  //"Malawi"
      '149' => '458',  //"Malaysia"
      '146' => '462',  //"Maldives"
      '136' => '466',  //"Mali"
      '144' => '470',  //"Malta"
      '135' => '584',  //"Marshall Islands"
      '141' => '474',  //"Martinique"
      '142' => '478',  //"Mauritania"
      '145' => '480',  //"Mauritius"
      '233' => '175',  //"Mayotte"
      '148' => '484',  //"Mexico"
      '69' => '583',   //"Micronesia"
      '133' => '498',  //"Moldova, Republic Of"
      '132' => '492',  //"Monaco"
      '137' => '496',  //"Mongolia"
      '143' => '500',  //"Monserrat"
      '131' => '504',  //"Morocco"
      '150' => '508',  //"Mozambique"
      '138' => '104',  //"Myanmar"
      '151' => '516',  //"Nambia"
      '160' => '520',  //"Nauru"
      '159' => '524',  //"Nepal"
      '157' => '528',  //"Netherlands"
      '240' => '528',  //"Netherlands Antilles"
      '152' => '540',  //"New Caledonia"
      '162' => '554',  //"New Zealand"
      '156' => '558',  //"Nicaragua"
      '153' => '562',  //"Niger"
      '155' => '566',  //"Nigeria"
      '161' => '570',  //"Niue"
      '154' => '574',  //"Norfolk Island"
      '140' => '580',  //"Northern Mariana Islands"
      '158' => '578',  //"Norway"
      '163' => '512',  //"Oman"
      '239' => '000',  //"Other"
      '169' => '586',  //"Pakistan"
      '175' => '585',  //"Palau"
      '164' => '591',  //"Panama"
      '167' => '598',  //"Papua New Guinea"
      '176' => '600',  //"Paraguay"
      '165' => '604',  //"Peru"
      '168' => '608',  //"Philippines"
      '172' => '612',  //"Pitcairn Island"
      '170' => '616',  //"Poland"
      '174' => '620',  //"Portugal"
      '173' => '630',  //"Puerto Rico"
      '177' => '634',  //"Qatar"
      '178' => '638',  //"Réunion"
      '179' => '642',  //"Romania"
      '180' => '643',  //"Russian Federation"
      '181' => '646',  //"Rwanda"
      '122' => '662',  //"Saint Lucia"
      '231' => '882',  //"Samoa"
      '193' => '674',  //"San Marino"
      '197' => '678',  //"Sao Tome & Principe"
      '182' => '682',  //"Saudi Arabia"
      '194' => '686',  //"Senegal"
      '184' => '690',  //"Seychelles"
      '192' => '694',  //"Sierra Leone"
      '187' => '702',  //"Singapore"
      '191' => '703',  //"Slovakia"
      '189' => '705',  //"Slovenia"
      '183' => '090',  //"Solomon Islands"
      '195' => '706',  //"Somalia"
      '235' => '710',  //"South Africa"
      '86' => '239',   //"South Georgia and the South Sandwich Islands"
      '64' => '724',   //"Spain"
      '124' => '144',  //"Sri Lanka"
      '188' => '654',  //"St. Helena"
      '114' => '659',  //"St. Kitts And Nevis"
      '242' => '663',  //"St. Maarten"
      '171' => '666',  //"St. Pierre & Miquelon"
      '243' => '670',  //"St. Vincent & the Grenandines"
      '185' => '729',  //"Sudan"
      '196' => '740',  //"Suriname"
      '190' => '744',  //"Svalbard & Jan Mayen Islands"
      '200' => '748',  //"Swaziland"
      '186' => '752',  //"Sweden"
      '40' => '756',   //"Switzerland"
      '199' => '760',  //"Syrian Arab Republic"
      '215' => '158',  //"Taiwan, Province Of China"
      '206' => '762',  //"Tajikistan (CAR)"
      '244' => '834',  //"Tanzania"
      '205' => '764',  //"Thailand"
      '211' => '626',  //"Timor Leste"
      '204' => '768',  //"Togo"
      '207' => '772',  //"Tokelau"
      '210' => '776',  //"Tonga"
      '213' => '780',  //"Trinidad & Tobago"
      '209' => '788',  //"Tunisia"
      '212' => '792',  //"Turkey"
      '208' => '795',  //"Turkmenistan"
      '201' => '796',  //"Turks & Caicos Islands"
      '214' => '798',  //"Tuvalu"
      '218' => '800',  //"Uganda"
      '217' => '804',  //"Ukraine"
      '2' => '784',    // "United Arab Emirates"
      '74' => '826',   //"United Kingdom (Great Britain)"
      '219' => '581',  //"United States Minor Outlying Islands"
      '220' => '840',  //"United States Of America"
      '227' => '850',  //"United States Virgin Islands"
      '246' => '000',  //"Unknown"
      '221' => '858',  //"Uruguay"
      '222' => '860',  //"Uzbekistan"
      '229' => '548',  //"Vanuatu"
      '223' => '336',  //"Vatican City State (Holy See)"
      '225' => '862',  //"Venezuela"
      '228' => '704',  //"Viet Nam"
      '230' => '876',  //"Wallis & Futuna Islands"
      '62' => '732',   //"Western Sahara"
      '232' => '887',  //"Yemen"
      '234' => '891',  // Yugoslavia",
      '237' => '180',  //"Zaire"
      '236' => '894',  //"Zambia"
      '238' => '716',  //"Zimbabwe"
    );
    if (isset($countrymap[$value])) {
      return $countrymap[$value];
    }
    else {
      return '000';
    }
  }
}
