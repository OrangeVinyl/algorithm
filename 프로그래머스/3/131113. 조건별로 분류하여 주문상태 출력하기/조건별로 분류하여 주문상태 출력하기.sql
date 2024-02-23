-- 5월 1일을 기준으로 
-- 출고여부는 5월 1일까지 출고완료로  | 이 후 날짜는 출고 대기로  | 미정이면 출고미정으로 출력
-- 결과는 주문 ID를 기준으로 오름차순 정렬
SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, '%Y-%m-%d'),
CASE
    WHEN DATEDIFF('2022-05-02', OUT_DATE) >= 1 THEN '출고완료'
    WHEN DATEDIFF('2022-05-02', OUT_DATE) < 1 THEN '출고대기'
    WHEN OUT_DATE IS NULL THEN '출고미정'
    END AS 출고여부
    
FROM FOOD_ORDER
ORDER BY ORDER_ID