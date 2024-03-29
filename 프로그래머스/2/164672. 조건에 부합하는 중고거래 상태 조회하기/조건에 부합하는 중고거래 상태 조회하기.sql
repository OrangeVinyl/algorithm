-- 2022년 10월 5일
-- 거래 상태가 SALE이면 판매중, RESERVED이면 예약중, DONE 이면 거래완료로 분류하여 출력
-- 게시글 ID 기준으로 내림차순
SELECT BOARD_ID, WRITER_ID, TITLE, PRICE, CASE WHEN STATUS like 'SALE' THEN '판매중' WHEN STATUS like 'RESERVED' THEN '예약중' WHEN STATUS like 'DONE' THEN '거래완료' END AS STATUS
FROM USED_GOODS_BOARD
WHERE CREATED_DATE like '2022-10-05'
ORDER BY BOARD_ID DESC