-- 코드를 작성해주세요
WITH SKILL_CODES AS (
    SELECT SC.CODE 
    FROM SKILLCODES SC
    WHERE SC.NAME = 'Python' OR SC.NAME = 'C#'
)
SELECT DISTINCT dev.id, dev.email, dev.first_name, dev.last_name
FROM DEVELOPERS dev 
    INNER JOIN SKILL_CODES scs 
    ON (dev.SKILL_CODE & scs.CODE) = scs.CODE
ORDER BY dev.ID ASC;