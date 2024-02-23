-- 2022년 4월 13일  / 취소되지 않은 /  흉부외과(CS) / 진료 예약 내역
SELECT A.APNT_NO, P.PT_NAME, P.PT_NO, A.MCDP_CD, D.DR_NAME, A.APNT_YMD
FROM APPOINTMENT A
JOIN DOCTOR D ON(A.MDDR_ID = D.DR_ID)
JOIN PATIENT P ON(A.PT_NO = P.PT_NO)
WHERE A.MCDP_CD = 'CS' AND APNT_CNCL_YN = 'N' AND A.APNT_YMD LIKE '2022-04-13%'
ORDER BY APNT_YMD