core = 7.18
api = 2

; Contrib
projects[achievements][subdir] = "contrib"
projects[achievements][version] = "1.5"
projects[boxes][subdir] = "contrib"
projects[boxes][version] = "1.0"
projects[colorbox][subdir] = "contrib"
projects[colorbox][version] = "2.0"
projects[context][subdir] = "contrib"
projects[context][version] = "3.0-beta6"
projects[context_og][subdir] = "contrib"
projects[context_og][version] = "2.1"
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.2"
projects[date][subdir] = "contrib"
projects[date][version] = "2.6"
projects[ds][subdir] = "contrib"
projects[ds][version] = "1.6"
projects[editablefields][subdir] = "contrib"
projects[editablefields][version] = "1.x-dev"
projects[email_registration][subdir] = "contrib"
projects[email_registration][version] = "1.0"
projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-rc3"
projects[entityreference][subdir] = "contrib"
projects[entityreference][version] = "1.0"
projects[entityreference_prepopulate][subdir] = "contrib"
projects[entityreference_prepopulate][version] = "1.1"
projects[epub_export][subdir] = "contrib"
projects[epub_export][version] = "1.x-dev"
projects[features][subdir] = "contrib"
projects[features][version] = "1.x-dev"
projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.1"
projects[features_date_formats][subdir] = "contrib"
projects[features_date_formats][type] = module
projects[features_date_formats][download][type] = 'git'
projects[features_date_formats][download][url] = "http://git.drupal.org/sandbox/rballou/1699026.git"
projects[features_date_formats][download][revision] = "b4a286a25b06b3fd7d158fbe5fd12e808ec53187"
projects[formblock][subdir] = "contrib"
projects[formblock][version] = "1.x-dev"
projects[insert][subdir] = "contrib"
projects[insert][version] = "1.2"
projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.0"
projects[link][subdir] = "contrib"
projects[link][version] = "1.0"
projects[linkit][subdir] = "contrib"
projects[linkit][version] = "2.5"
projects[logintoboggan][subdir] = "contrib"
projects[logintoboggan][version] = "1.3"
projects[menu_block][subdir] = "contrib"
projects[menu_block][version] = "2.3"
projects[migrate][subdir] = "contrib"
projects[migrate][version] = "2.4"
projects[og][subdir] = "contrib"
projects[og][version] = "2.0-beta4"
projects[og_workflow][subdir] = "contrib"
projects[og_workflow][download][type] = git
projects[og_workflow][download][branch] = 7.x-2.x
projects[og_workflow][download][url] = http://git.drupal.org/project/og_workflow.git
projects[og_workflow][download][revision] = "02f48bdeea0c9c5cb12009921b75f59aa4e43b89"
projects[realname][subdir] = "contrib"
projects[realname][version] = "1.0"
projects[quiz][subdir] = "contrib"
projects[quiz][version] = "4.0-alpha10"
projects[sharethis][subdir] = "contrib"
projects[sharethis][version] = "2.5"
projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"
projects[token][subdir] = "contrib"
projects[token][version] = "1.4"
projects[video_filter][subdir] = "contrib"
projects[video_filter][version] = "3.1"


# uuid_menu_link was removed after commit 2fde46e883c9e445edad5c2929396e7146e41a68
# pin the checkout for now.
projects[uuid][subdir] = "contrib"
projects[uuid][download][type] = git
projects[uuid][download][url] = http://git.drupal.org/project/uuid.git
projects[uuid][download][revision] = "2fde46e883c9e445edad5c2929396e7146e41a68"
projects[uuid_features][subdir] = "contrib"
projects[uuid_features][version] = "1.x-dev"

projects[views][subdir] = "contrib"
projects[views][version] = "3.5"
projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.0"
projects[views_data_export][subdir] = "contrib"
projects[views_data_export][version] = "3.0-beta6"
projects[webform][subdir] = "contrib"
projects[webform][version] = "3.18"
projects[workflow][subdir] = "contrib"
projects[workflow][version] = "1.x-dev"
projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.2"

; Patches
; http://drupal.org/node/965450#comment-5837286
projects[uuid_features][patch][] = "http://drupal.org/files/uuid_features-965450-21.patch"

; http://drupal.org/node/1694894
projects[formblock][patch][] = "http://drupal.org/files/formblock-1694894-1.patch"

; http://drupal.org/node/1694940 (needs re-roll after 1167076)
projects[formblock][patch][] = "http://drupal.org/files/formblock-1694940-8.patch"

; http://drupal.org/node/1706914
projects[formblock][patch][] = "http://drupal.org/files/formblock-1706914-2.patch"

; http://drupal.org/node/1719824
projects[editablefields][patch][] = "http://drupal.org/files/editablefields-stale-entity-in-form-state.patch"

; http://drupal.org/node/1853146
projects[og_workflow][patch][] = "http://drupal.org/files/og_workflow-1853146-2-allow-control-of-group-nodes.patch"

; http://drupal.org/node/1380954#comment-5700818
projects[workflow][patch][] = "http://drupal.org/files/triggers-1380954.patch"

; http://drupal.org/node/1719414
projects[uuid_features][patch][] = "http://drupal.org/files/uuid_features-1719414-5.patch"

; http://drupal.org/node/1852096
projects[achievements][patch][] = "http://drupal.org/files/achievements-1852096-3-achievements_delete.patch"

; http://drupal.org/node/1807916#comment-6711528
projects[views][patch][] = "http://drupal.org/files/views-exposed-form-reset-redirect-1807916-4.patch"

; http://drupal.org/node/1752062#comment-6508672
projects[views][patch][] = "http://drupal.org/files/views-1752062-11.patch"

; https://drupal.org/node/1792932
projects[quiz][patch][] = "https://drupal.org/files/quiz-allow_resume-1792932-13.patch"

; Development only modules
projects[devel][subdir] = "development"
projects[devel][version] = "1.3"
projects[diff][subdir] = "development"
projects[diff][version] = "3.2"

; Libraries
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.tar.gz"
libraries[ckeditor][download][sha1] = bce8285fb357c49cc0a896b0aed639212ea68699
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"
;libraries[ckeditor][patch][] = "ckeditor-open-links-in-new-window.patch"

libraries[FunnyMonkey-EPUB-Package][type] = library
libraries[FunnyMonkey-EPUB-Package][download][type] = git
libraries[FunnyMonkey-EPUB-Package][download][branch] = master
libraries[FunnyMonkey-EPUB-Package][download][url] = https://github.com/FunnyMonkey/FunnyMonkey-EPUB-Package.git
libraries[FunnyMonkey-EPUB-Package][destination] = "libraries"

libraries[bootstrap][type] = library
libraries[bootstrap][download][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip
libraries[bootstrap][download][type] = "get"
libraries[bootstrap][destination] = "libraries"

libraries[colorbox][download][type] = get
libraries[colorbox][download][url] = http://jacklmoore.com/colorbox/colorbox.zip
