-- 코드를 작성해주세요
WITH RARES AS (
    SELECT * FROM ITEM_INFO
    WHERE RARITY = 'RARE'
)
SELECT UI.ITEM_ID, UI.ITEM_NAME, UI.RARITY
FROM ITEM_INFO UI
WHERE UI.ITEM_ID IN (
    SELECT I.ITEM_ID
    FROM RARES R INNER JOIN ITEM_TREE I ON I.PARENT_ITEM_ID = R.ITEM_ID
)
ORDER BY UI.ITEM_ID DESC;