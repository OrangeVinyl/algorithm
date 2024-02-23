-- 입양을 간 동물 중
-- 보호 기간이 가장 길었던 동물 두 마리의 아이디와 이름을
-- 이때 결과는 보호 기간이 긴 순으로 조회해야 합니다.
select animal_id, name
from (
    SELECT animal_id, o.name, o.datetime - i.datetime as time
    from animal_outs o
    inner join animal_ins i using(animal_id)
    order by time desc
    limit 2
) ret