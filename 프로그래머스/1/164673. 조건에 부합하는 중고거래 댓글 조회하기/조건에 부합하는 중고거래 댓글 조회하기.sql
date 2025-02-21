-- 코드를 입력하세요
SELECT B.TITLE, B.BOARD_ID, R.REPLY_ID, R.WRITER_ID, R.CONTENTS, 
    date_format(R.CREATED_DATE, '%Y-%m-%d') AS CREATED_DATE
FROM USED_GOODS_BOARD B INNER JOIN USED_GOODS_REPLY R ON B.BOARD_ID = R.BOARD_ID
WHERE (
    year(B.CREATED_DATE) = 2022 
    AND month(B.CREATED_DATE) = 10
)
ORDER BY R.CREATED_DATE ASC, B.TITLE ASC;