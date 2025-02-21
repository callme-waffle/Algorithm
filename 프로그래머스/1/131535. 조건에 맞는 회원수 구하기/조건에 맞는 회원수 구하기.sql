-- 코드를 입력하세요
SELECT count(*) AS USERS
FROM USER_INFO
WHERE year(JOINED) = 2021 AND age >= 20 AND age <= 29;