<?php

$aliases['stg-ghel'] = array (
    'root' => '/server/www/ghel',
    'uri' => 'http://ghel.staging.sqm.io',
    'path-aliases' =>  array (
        '%files' => 'sites/default/files',
        '%site' => 'sites/default/',
        '%dump' => '/tmp/drush-dump-' . date('Ymdhis') . '.sql',
    ),
    'remote-host' => 'staging.sqm.io',
    'ssh-options' => '-p 22421',
    'command-specific' => array (
        'sql-sync' => array (
            'no-ordered-dump' => TRUE,
            'structure-tables' => array(
                // You can add more tables which contain data to be ignored by the database dump
                'common' => array('cache', 'cache_filter', 'cache_menu', 'cache_page', 'history', 'sessions', 'watchdog'),
            ),
        ),
    ),
);

$aliases['dev-ghel'] = array (
    'root' => '/server/www/ghel',
    'uri' => 'http://dev-ghel.sqm.private',
    'path-aliases' =>  array (
        '%files' => 'sites/default/files',
        '%site' => 'sites/default/',
        '%dump' => '/tmp/drush-dump-' . date('Ymdhis') . '.sql',
    ),
    'remote-host' => 'dev-ghel.sqm.private',
    'ssh-options' => '-p 22421',
    'command-specific' => array (
        'sql-sync' => array (
            'no-ordered-dump' => TRUE,
            'structure-tables' => array(
                // You can add more tables which contain data to be ignored by the database dump
                'common' => array('cache', 'cache_filter', 'cache_menu', 'cache_page', 'history', 'sessions', 'watchdog'),
            ),
        ),
    ),
);


$aliases['dev-ghel-ob'] = array (
    'root' => '/server/www/ghel',
    'uri' => 'http://dev-ghel-ob.sqm.private',
    'path-aliases' =>  array (
        '%files' => 'sites/default/files',
        '%site' => 'sites/default/',
        '%dump' => '/tmp/drush-dump-' . date('Ymdhis') . '.sql',
    ),
    'remote-host' => 'dev-ghel-ob.sqm.private',
    'ssh-options' => '-p 22421',
    'command-specific' => array (
        'sql-sync' => array (
            'no-ordered-dump' => TRUE,
            'structure-tables' => array(
                // You can add more tables which contain data to be ignored by the database dump
                'common' => array('cache', 'cache_filter', 'cache_menu', 'cache_page', 'history', 'sessions', 'watchdog'),
            ),
        ),
    ),
);
