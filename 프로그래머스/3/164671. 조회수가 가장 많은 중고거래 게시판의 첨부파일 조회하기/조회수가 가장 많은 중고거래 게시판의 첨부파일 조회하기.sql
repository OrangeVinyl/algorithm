SELECT concat("/home/grep/src/", board_id, "/", file_id, file_name, file_ext) as FILE_PATH
from used_goods_board b
join used_goods_file f using(board_id)
where views = (select max(views) from used_goods_board)
order by file_id desc
