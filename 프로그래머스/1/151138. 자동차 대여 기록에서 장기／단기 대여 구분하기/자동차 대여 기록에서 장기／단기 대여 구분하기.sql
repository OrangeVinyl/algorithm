SELECT history_id, car_id, date_format(start_date, '%Y-%m-%d') as start_date, date_format(end_date, '%Y-%m-%d') as end_date, case when (DATEDIFF(END_DATE,START_DATE) +1) >= 29 then '장기 대여' else '단기 대여' end as 'RENT_TYPE'
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE DATE_FORMAT(START_DATE,'%Y-%m') = '2022-09'
order by 1 desc