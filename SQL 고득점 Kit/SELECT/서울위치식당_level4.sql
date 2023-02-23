SELECT ri.rest_id, ri.rest_name, ri.food_type, ri.favorites, ri.address, round(avg(rr.review_score),2) as review_score 
from rest_info ri
join rest_review rr
on ri.rest_id = rr.rest_id 
where ri.address like '서울%'
group by ri.rest_id
order by review_score desc, favorites desc

# 왜 group by를 사용해야 할까 고민이 많이 된다.
