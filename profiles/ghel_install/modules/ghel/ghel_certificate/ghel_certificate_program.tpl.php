<!--
  note that this markup is not ideal, but was written to accomodate issues
  with the and was written to workaround issues with the mpdf library the
  markup was tested with version 5.6.1 of the mpdf library. This will likely
  need refactoring if the mpdf library is updated.
-->

<table class="certificate-container" cellspacing="0">
  <tr>
    <td colspan="3"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_header.gif" /></td>
  </tr>
  <tr>
    <td class="cert-left"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_left.gif" /> </td>
    <td class="cert-content">
      <br />
      <img class="logo" src="profiles/ghel_install/modules/ghel/ghel_certificate/images/global_health_logo.gif" />
      <br /><br /><br /><br /><br /><br />
      <img class="complete" src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_complete.gif" />
      <br /><br /><br /><br /><br /><br />
      <div class="verify">
        <span class="verify-header"><?php print t('This is to verify that');?></span>
        <div class="name"><?php print t('@first_name @last_name', array('@first_name' => $first_name, '@last_name' => $last_name)); ?></div>
        <div class="verify-text">
          <div><?php print t('has successfully completed the '); ?><span class="course-name"><?php print check_plain($title);?></span> course</div>
          <div class="date"><?php print check_plain($pass_date); ?></div>
        </div>
      </div>
      <br /><br /><br /><br /><br /><br />
      <div class="signature">
        <span class="signature-1"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_sig1.gif" /></span>
        <span class="signature-2"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_sig2.gif" /></span>
      </div>
      <br /><br /><br /><br />
      <div class="sponsors">
        <span class="usaid"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_usaid.gif" /></span>
        <span class="jhb"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_jhb.gif" /></span>
      </div>
      &nbsp;
    </td>
    <td class="cert-right"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_right.gif" />&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td colspan="3" class="cert-footer"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_footer.gif" /></td>
  </tr>
</table>
<br />
<table class="certificate-container page-two" cellspacing="0">
  <tr>
    <td colspan="3"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_header.gif" /></td>
  </tr>
  <tr>
    <td class="cert-left"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_left.gif" /> </td>
    <td class="cert-content">
      <br />
      <img class="logo" src="profiles/ghel_install/modules/ghel/ghel_certificate/images/global_health_logo.gif" />
      <br /><br /><br /><br /><br /><br />
      <div class="addendum">
        <div><?php print t('This is an addendum to the') ?></div>
        <div>
          <?php print t('Certificate of Program Completion for'); ?>
          <span class="course-name"><?php print check_plain($title);?></span>
        </div>
        <div><?php print t('This program consists of the following courses:') ?></div>
        <div class="course-list">
          <?php print $courses; ?>
        </div>
        <div class="by-line">
          <?php print t('All of these courses have been completed by @first_name @last_name', array('@first_name' => $first_name, '@last_name' => $last_name))?>
        </div>
      </div>
      <br /><br /><br /><br />
      <div class="sponsors">
        <span class="usaid"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_usaid.gif" /></span>
        <span class="jhb"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_jhb.gif" /></span>
      </div>
      &nbsp;
    </td>
    <td class="cert-right"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_right.gif" />&nbsp;&nbsp;&nbsp;</td>
  </tr>
  <tr>
    <td colspan="3" class="cert-footer"><img src="profiles/ghel_install/modules/ghel/ghel_certificate/images/cert_footer.gif" /></td>
  </tr>
</table>
