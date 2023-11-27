SELECT animal_type, if(name is null,'No name', name) as Name, sex_upon_intake from animal_ins
order by animal_id asc