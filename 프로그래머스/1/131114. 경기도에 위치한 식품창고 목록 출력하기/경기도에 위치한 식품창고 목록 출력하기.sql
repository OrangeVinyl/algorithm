-- 창고의 ID, 이름, 주소, 냉동시설 여부
-- 냉동시설 여부가 NULL인 경우, 'N'으로 출력
-- 창고 ID asc
SELECT WAREHOUSE_ID, WAREHOUSE_NAME, ADDRESS, case when freezer_yn is null then 'N' else freezer_yn end as FREEZER_YN
from FOOD_WAREHOUSE 
where ADDRESS like '경기도%'
order by 1