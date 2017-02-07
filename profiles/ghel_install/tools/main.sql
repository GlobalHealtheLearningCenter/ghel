drop database funnymonkey_import;
create database funnymonkey_import;
use funnymonkey_import;
set sql_mode='PIPES_AS_CONCAT,ANSI_QUOTES,IGNORE_SPACE,NO_KEY_OPTIONS,NO_TABLE_OPTIONS,NO_FIELD_OPTIONS,NO_BACKSLASH_ESCAPES';
warnings;
source schema.sql;

source country.sql;
source course.sql;
source glossary.sql;
source courseglossary.sql;
source examStatus.sql;
source member.sql;
source topic.sql;
source page.sql;
source program.sql;
source programCourse.sql;
source question.sql;
source questionType.sql;
source questionresponse.sql;
source memberProgramComplete.sql;

source fini.sql;
