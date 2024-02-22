-- 2021년에 가입한 전체 회원들 중
-- 상품을 구매한 회원 수, 상품을 구매한 회원의 비율(소수 둘째점에서 반올림), 년 / 월 기준으로 
-- 년 기준으로 오름차순 정렬 , 월 기준 오름차순

WITH USER_2021_INFO AS
(SELECT *
FROM USER_INFO
WHERE YEAR(JOINED) = 2021)

select year(sales_date) as YEAR, month(sales_date) as MONTH, count(distinct(user_id)) as purchased_users, ROUND(count(distinct(user_id)) / (select count(*) from USER_2021_INFO), 1) as purchased_ratio
from (
SELECT *
from online_sale
join (select * from user_info where year(joined) = '2021' ) info using(user_id)
) sub
group by YEAR, MONTH
order by 1, 2