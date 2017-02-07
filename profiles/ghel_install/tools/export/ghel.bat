bcp USAID.dbo.country format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\country.xml
bcp USAID.dbo.country out c:\temp\export\country.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\country.xml

bcp USAID.dbo.course format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\course.xml
bcp USAID.dbo.course out c:\temp\export\course.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\course.xml

bcp USAID.dbo.courseGlossary format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\courseGlossary.xml
bcp USAID.dbo.courseGlossary out c:\temp\export\courseGlossary.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\courseGlossary.xml

bcp USAID.dbo.examStatus format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\examStatus.xml
bcp USAID.dbo.examStatus out c:\temp\export\examStatus.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\examStatus.xml

bcp USAID.dbo.glossary format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\glossary.xml
bcp USAID.dbo.glossary out c:\temp\export\glossary.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\glossary.xml

bcp USAID.dbo.member format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\member.xml
bcp USAID.dbo.member out c:\temp\export\member.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\member.xml

bcp USAID.dbo.memberProgramComplete format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\memberProgramComplete.xml
bcp USAID.dbo.memberProgramComplete out c:\temp\export\memberProgramComplete.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\memberProgramComplete.xml

bcp USAID.dbo.page format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\page.xml
bcp USAID.dbo.page out c:\temp\export\page.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\page.xml

bcp USAID.dbo.program format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\program.xml
bcp USAID.dbo.program out c:\temp\export\program.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\program.xml

bcp USAID.dbo.programcourse format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\programcourse.xml
bcp USAID.dbo.programcourse out c:\temp\export\programcourse.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\programcourse.xml

bcp USAID.dbo.question format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\question.xml
bcp USAID.dbo.question out c:\temp\export\question.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\question.xml

bcp USAID.dbo.questionResponse format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\questionResponse.xml
bcp USAID.dbo.questionResponse out c:\temp\export\questionResponse.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\questionResponse.xml

bcp USAID.dbo.questionType format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\questionType.xml
bcp USAID.dbo.questionType out c:\temp\export\questionType.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\questionType.xml

bcp USAID.dbo.topic format nul -S FM-JEFF\SQLEXPRESS -T -w -x -t x@x@x -r \0\0\0\0\r\n -f c:\temp\export\topic.xml
bcp USAID.dbo.topic out c:\temp\export\topic.tsv -S FM-JEFF\SQLEXPRESS -T -w -f c:\temp\export\topic.xml
