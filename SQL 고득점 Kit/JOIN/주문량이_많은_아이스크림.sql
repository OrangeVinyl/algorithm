with A as (
    select * from first_half
    union all
    select * from july
)

SELECT flavor from A
group by flavor
order by sum(total_order) desc limit 3