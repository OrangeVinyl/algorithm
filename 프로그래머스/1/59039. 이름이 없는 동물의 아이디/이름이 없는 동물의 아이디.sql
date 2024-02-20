-- ANIMAL_ID
-- 이름이 없는 채로 들어온 동물의 ID를 조회하는 SQL 
-- 단, ID는 오름차순 정렬

SELECT animal_id 
from animal_ins
where name is null
order by 1