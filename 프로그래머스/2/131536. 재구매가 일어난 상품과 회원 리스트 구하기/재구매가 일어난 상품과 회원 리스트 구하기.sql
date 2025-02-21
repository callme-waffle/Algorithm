SELECT S.USER_ID, S.PRODUCT_ID
FROM ONLINE_SALE AS S
GROUP BY S.USER_ID, S.PRODUCT_ID
HAVING count(*) > 1
ORDER BY S.USER_ID, S.PRODUCT_ID DESC