-- 아이템의 희귀도가 'RARE' 인 모든 다음 업그레이드 아이템



select i.item_id, i.item_name, i.rarity
from item_info i
join (
    select f.item_id, item_name, rarity, t.item_id as 'next_upgrade'
    from (select * from item_info where rarity = 'RARE') f
    join item_tree t on (t.parent_item_id = f.item_id)
) j on i.item_id = j.next_upgrade
order by 1 desc