#!/bin/bash
# These next few lines are defaults modify these to your local environment
# to avoid having to re-type at each rebuild.
DEFBUILDDIR=/tmp/ghel
DEFGITUSER=git
#DEFGITBRANCH=master
DEFGITURI=atendg.beanstalkapp.com:/ghel.git

MAKEFILE=bootstrap.make

echo 
echo "#########################################################################"
echo "# Note: Your build will fail to apply patches even though it generates  #"
echo "#       a proper PATCHES.txt for each patched module unless you have    #"
echo "#       the following patch applied to your drush:                      #"
echo "#                                                                       #"
echo "#  http://drupal.org/files/drush-1276872-git-fail-apply-patches.patch   #"
echo "#                                                                       #"
echo "# See: http://drupal.org/node/1276872                                   #"
echo "#########################################################################"
echo 

# No edits below here should be necessary
read -p "Build Directory [${DEFBUILDDIR}]: " ghelbuilddir
ghelbuilddir=${ghelbuilddir:-$DEFBUILDDIR}

#read -p "GITUSER [${DEFGITUSER}]: " ghelgituser
#ghelgituser=${ghelgituser:-$DEFGITUSER}

#read -p "GITURI [${DEFGITURI}]: " ghelgituri
#ghelgituri=${ghelgituri:-$DEFGITURI}

#read -p "GIT BRANCH [${DEFGITBRANCH}]: " ghelgitbranch
#ghelgitbranch=${ghelgitbranch:-$DEFGITBRANCH}

echo "Building ghel in ${ghelbuilddir}"
drush make  --no-gitinfofile --working-copy ${MAKEFILE} "${ghelbuilddir}"
