#!/bin/bash
user=root
password=root
database=emma
query="DELETE FROM cache_form WHERE expire < UNIX_TIMESTAMP(DATE_SUB(NOW(), INTERVAL 1 DAY))"


echo "Deleting form_cache"
#Remove cache_form records where expire < yesterday at this time
mysql --user="$user" --password="$password" --database="$database" --execute="$query"

echo "Disable Backup Migrate Module"
#drush pm-disable backup_migrate;

echo "Running Epub Export Cron"
#Run epub_export cron first
drush cron -v --debug epub_export 2>&1 | tee sites/default/files/cron/epub_export_output.txt;

echo "Running Cron"
drush cron -v --debug epub_export 2>&1 | tee sites/default/files/cron/cron_output.txt;

echo "Enabling Elysia Cron"
#Enable Elysia Cron
drush en elysia_cron;

echo "Finished"