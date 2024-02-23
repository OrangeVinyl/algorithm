-- 중고 거래 게시물을 3건 이상 등록한 사용자
-- 전체 주소는 시, 도로명 주소, 상세 주소가 함께 출력되도록 해주시고
-- 전화번호의 경우 xxx-xxxx-xxxx 같은 형태로 하이픈 문자열(-)을 삽입
-- 결과는 회원 ID를 기준으로 내림차순 정렬

SELECT 
USER_ID, NICKNAME, CONCAT(CITY, ' ',STREET_ADDRESS1, ' ', STREET_ADDRESS2) AS 전체주소,
CONCAT(SUBSTR(TLNO, 1,3), '-', SUBSTR(TLNO,4,4), '-', SUBSTR(TLNO,8)) AS 전화번호

FROM USED_GOODS_USER g
JOIN (SELECT * FROM USED_GOODS_BOARD GROUP BY WRITER_ID HAVING COUNT(*) >= 3) b ON(g.USER_ID = b.WRITER_ID)
ORDER BY USER_ID DESC