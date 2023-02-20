SELECT USER_ID, PRODUCT_ID from ONLINE_SALE
Group by user_id, product_id 
having count(user_id) >= 2
ORDER BY USER_ID asc, PRODUCT_ID desc