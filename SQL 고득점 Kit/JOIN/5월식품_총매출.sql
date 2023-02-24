SELECT fp.product_id, fp.product_name, (fp.price * fd.amount) as total_sales 
from food_product as fp 
inner join     
(select product_id, sum(amount) as amount from food_order
where date_format(produce_date,'%Y-%m') = '2022-05' group by product_id)
as fd 
on fd.product_id = fp.product_id
order by total_sales desc, product_id asc