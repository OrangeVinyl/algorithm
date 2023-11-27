SELECT distinct(car_info.car_id), car_info.car_type, round((car_info.daily_fee * (100-car_discount.discount_rate) / 100 *30)) as FEE 
from CAR_RENTAL_COMPANY_CAR as car_info
left join CAR_RENTAL_COMPANY_RENTAL_HISTORY as car_history 
on car_info.car_id = car_history.car_id
left join CAR_RENTAL_COMPANY_DISCOUNT_PLAN as car_discount
on car_info.car_type = car_discount.car_type

where car_info.car_type in ('세단', 'SUV')
and car_info.car_id not in 
(select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY where '2022-11' between date_format(start_date, '%Y-%m') and date_format(end_date, '%Y-%m'))
and car_discount.duration_type = '30일 이상'
and (car_info.daily_fee * (100-car_discount.discount_rate) / 100 *30) between 500000 and 2000000

order by FEE desc, car_type asc, car_id desc





-- 자동차 종류 세단 or SUV 중 2022/11/1 ~ 2022/11/30 대여가능 + 30일간 대여금액 50<=x<200 
-- 자동차 ID, 자동차 종류, 대여금액(FEE) 
-- 대여금액 내림차순, 자동차 종류 오름차순, 자동차 ID 내림차순