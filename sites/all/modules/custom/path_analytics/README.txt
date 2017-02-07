INTRODUCTION
------------
The Path Analytics module pulls in Google Analytics data and provides it in a
basic report based on the path of an initial node. This allows you to provide
a basic report to site content developers for a section of the site, i.e. a
course and all it's content, an Organic Group and all it's content, etc.

INSTALLATION
------------
Using Drush: `drush en -y path_analytics`
This will automatically download any dependencies and enable all.

Using the web Admin area:
1. Copy path_analytics folder to modules directory (usually sites/all/modules).
2. Make sure you have the following modules this module depends on:
     chart
     google_analytics_reports
     google_analytics_api
     date_popup
3. At admin/build/modules enable the Path Analytics (and it's dependencies) module.


CONFIGURATION
-------------
1. Assign the "Access Google Analytics Reports" permission.
2. Go to /admin/config/system/google-analytics-reports and provide permission
   to access your Google Analytics profile(s), then select the profile and settings.
3. Go to /admin/config/system/path_analytics and select the node(s) you want to use
   as the base or main path for reporting as well as whether or not to provide
   a local task for accessing the report. Click "Save".

You're in business!
