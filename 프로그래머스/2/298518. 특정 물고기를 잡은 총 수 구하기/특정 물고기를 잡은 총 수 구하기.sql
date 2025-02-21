-- 코드를 작성해주세요
SELECT count(*) AS FISH_COUNT
FROM FISH_INFO
WHERE fish_type IN (
    SELECT fish_type FROM FISH_NAME_INFO
    WHERE fish_name = 'BASS' OR fish_name = 'SNAPPER'
);