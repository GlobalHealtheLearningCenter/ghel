core = 7.17
api = 2

projects[drupal][type] = "core"
; http://drupal.org/node/1352924
; http://drupal.org/node/1146244
projects[drupal][patch][] = "http://drupal.org/files/1352924_9.patch"

projects[ghel_install][type] = "profile"
projects[ghel_install][download][type] = "git"
projects[ghel_install][download][url] = "git@atendg.beanstalkapp.com:/ghel.git"
projects[ghel_install][download][branch] = "master"
