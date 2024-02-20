WITH RECURSIVE time AS (
    SELECT 0 AS HOUR 
    UNION
    SELECT HOUR+1 FROM time WHERE HOUR < 23
)

select time.HOUR, count(animal_id) as 'COUNT'
from (select *, hour(datetime) as hour from animal_outs) a
right join time on time.hour = a.hour
group by hour
order by 1