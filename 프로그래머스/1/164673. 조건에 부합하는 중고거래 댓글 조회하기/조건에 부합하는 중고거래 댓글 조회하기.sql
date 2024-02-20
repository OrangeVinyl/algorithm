-- 게시글 제목, 게시글 ID, 댓글 ID, 댓글 작성자 ID, 댓글 내용, 댓글 작성일
SELECT TITLE, BOARD_ID, REPLY_ID, r.WRITER_ID, r.CONTENTS, date_format(r.created_date, '%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD b
join USED_GOODS_REPLY r using (BOARD_ID)
where b.CREATED_DATE like '2022-10%'
order by 6, 1
-- 2022년 10월

-- 댓글작성일 (오름차순) -> 게시물 오름차순