select item_id, item_name, rarity
from item_info i
left join 
(
select parent_item_id
from item_tree
where parent_item_id is not null
group by parent_item_id
) as j on (j.parent_item_id = i.item_id)
where j.parent_item_id is null
order by 1 desc


