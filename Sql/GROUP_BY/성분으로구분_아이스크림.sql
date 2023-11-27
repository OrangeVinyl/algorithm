SELECT ii.ingredient_type, sum(fh.total_order) as total_order from icecream_info as ii
inner join first_half as fh
on ii.flavor = fh.flavor
group by ingredient_type