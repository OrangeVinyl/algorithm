SELECT product_code, p.price * o.sales_amount_total as 'sales'
from product p
join (
    select product_id, sum(sales_amount) as sales_amount_total from offline_sale group by product_id
) o using(product_id)
 
order by 2 desc, 1 asc;