SELECT bk.category, sum(bs.sales) as total_sales from book_sales bs
join book bk on bs.book_id = bk.book_id
where sales_date like '2022-01-%'
group by category
order by category asc