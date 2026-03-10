-- 코드를 입력하세요
# SELECT MEMBER_ID, MEMBER_NAME, GENDER, 
#     date_format(M.DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH
# FROM MEMBER_PROFILE as M
# WHERE month(M.DATE_OF_BIRTH) = 3 AND M.TLNO IS NOT NULL
# ORDER BY M.MEMBER_ID ASC;

select MEMBER_ID
     , MEMBER_NAME
     , GENDER
     , date_format(DATE_OF_BIRTH, '%Y-%m-%d') as DATE_OF_BIRTH
  from MEMBER_PROFILE
 where month(DATE_OF_BIRTH) = 3
   and GENDER = 'W'
   and TLNO is not null
 order by MEMBER_ID
;