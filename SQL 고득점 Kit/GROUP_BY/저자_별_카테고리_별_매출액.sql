SELECT bk.AUTHOR_ID, at.AUTHOR_NAME, bk.CATEGORY, sum(bs.sales * bk.price) as TOTAL_SALES from BOOK bk
inner join AUTHOR as at on at.author_id = bk.author_id
inner join BOOK_SALES as bs on bs.book_id = bk.book_id
where bs.SALES_DATE like '2022-01-%'
group by bk.author_id, bk.category
order by AUTHOR_ID asc, CATEGORY desc