#!/bin/bash

DATABASE=funnymonkey_import
MYSQLUSER=root
MYSQLPASS=pass

read -p "MYSQL User [${MYSQLUSER}]: " dbuser
dbuser=${dbuser:-$MYSQLUSER}

read -sp "MYSQL Password [${MYSQLPASS}]: " dbpass
dbpass=${dbpass:-$MYSQLPASS}
echo "Resetting database..."
mysql -u${dbuser} -p${dbpass} -e "DROP DATABASE $DATABASE"
mysql -u${dbuser} -p${dbpass} -e "CREATE DATABASE $DATABASE"

mysql -u${dbuser} -p${dbpass} $DATABASE -e "SOURCE schema.sql"
echo "Importing tables..."
# @@@ tmpnam
TEMPFILE=/tmp/work.tsv
for n in $(cat tables.txt)
do
  echo "Doing $n"
  # Transcode the UTF-16 encoded input file into UTF-8 so we can work with it.
  iconv -f UTF-16 -t UTF-8 export/${n}.tsv > $TEMPFILE
  # Escape backslashes.
  sed -i -e 's/\\/\\\\/g' $TEMPFILE
  # Convert empty fields into NULLs.
  #sed -i -e 's/\t\t/\t\\N\t/g' $TEMPFILE
  sed -i -e 's/x@x@xx@x@x/x@x@x\\Nx@x@x/g' $TEMPFILE
  # Convert empty LAST field into NULL.
  #sed -i -e 's/\t\t\x00\x00\x00\x00/\t\\N\t\x00\x00\x00\x00/g' $TEMPFILE
  sed -i -e 's/x@x@x\x00\x00\x00\x00/x@x@x\\Nx@x@x\x00\x00\x00\x00/g' $TEMPFILE
  # Load it.
  echo "Loading $n"
  mysql -u${dbuser} -p${dbpass} $DATABASE -e "ALTER TABLE $n DISABLE KEYS;"
  # @@@ temp.
  mysql -u${dbuser} -p${dbpass} $DATABASE -e "DELETE FROM $n;"
  mysql --local-infile=1 -u${dbuser} -p${dbpass} $DATABASE -e "SET foreign_key_checks = 0;
load data local infile '$TEMPFILE' into table $n FIELDS TERMINATED BY 'x@x@x' LINES TERMINATED BY '\\0\\0\\0\\0\\r\\r\\n';
SET foreign_key_checks = 1;"
  mysql -u${dbuser} -p${dbpass} $DATABASE -e "ALTER TABLE $n ENABLE KEYS;"
done

cat ghel_glossary_fixup.csv > $TEMPFILE
mysql --local-infile=1 -u${dbuser} -p${dbpass} $DATABASE -e "LOAD DATA LOCAL INFILE '$TEMPFILE' INTO TABLE glossaryPatch FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '\"' ESCAPED BY '\"' LINES TERMINATED BY '\\n' IGNORE 1 LINES;"

mysql -u${dbuser} -p${dbpass} $DATABASE -e "SOURCE fini.sql"
