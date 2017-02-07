-- Inject course list.
UPDATE program p SET p.import_courses = (SELECT GROUP_CONCAT(pc.courseid) FROM programcourse pc WHERE pc.programid = p.programid GROUP BY pc.programid);

-- Fix alternatively empty response explanations.
UPDATE questionResponse set responseExplanation = '' WHERE responseExplanation IN ('<P>&nbsp;</P>', '&nbsp;');

-- Fix alternatively empty question explanations.
UPDATE question SET explanation = '' WHERE explanation IN('<br>', '<P>&nbsp;</P>', '&nbsp;', '&nbsp;&nbsp;');


-- Convert True/False questions that have responses filled in with other than True / False to multiple choice.
UPDATE question q, questionResponse r SET q.questionTypeID = 1 WHERE q.questionTypeID = 2 AND r.questionID = q.questionID AND r.response NOT IN ('True', 'False');


-- Convert True/False questions that have response-specific explanations to multiple choice.
UPDATE question q, questionResponse r SET q.questionTypeID = 1 WHERE q.questionTypeID = 2 AND r.questionID = q.questionID AND r.responseExplanation <> '';

-- Null out empty new_terms.
UPDATE glossaryPatch SET new_term = NULL WHERE new_term = '';
UPDATE glossaryPatch SET use_glossaryID = NULL WHERE use_glossaryID = 0;

-- Fix some spreadsheet glitches.
DELETE FROM glossaryPatch where glossaryID = use_glossaryID;

-- Relink courseGlossary
UPDATE IGNORE courseGlossary g, glossaryPatch p SET g.glossaryID = p.use_glossaryID where g.glossaryID = p.glossaryID AND p.use_glossaryID IS NOT NULL;
-- Clean up broken dupes.
DELETE courseGlossary FROM courseGlossary, glossaryPatch WHERE courseGlossary.glossaryID = glossaryPatch.glossaryID AND glossaryPatch.use_glossaryID IS NOT NULL;
