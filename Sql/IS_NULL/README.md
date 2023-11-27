## IF
IF(조건문, 참일 때의 값, 거짓일 때의 값)

```
SELECT IF(2 > 1, 'TRUE', 'FALSE') AS result
```

기본 사용 방식은 엑셀의 =IF() 와 같다.
아래와 같이 특정 컬럼 값의 조건에 의해서, 다른 컬럼의 출력하는 분기 처리도 가능하다.
엑셀 처럼 중첩 IF 의 사용도 가능하다.
```
SELECT IF(column_name is null, column_1, columnj_2) AS result
```

## IFNULL
IFNULL(column_name, value)
IFNULL() 함수는 해당 필드의 값이 NULL 을 반환할 때, 지정한 값으로 대체하여 출력해준다. 간단한 사용법은 아래와 같다.
```
SELECT IFNULL(column_name, '대체할 값') FROM [table_name]; 
```
이 역시 중첩해서 사용할 수 있다.
```
SELECT IFNULL(column_name, IFNULl(column_name, '대체할 값')) FROM [table_name]; 
```

## ISNULL
ISNULL(column_name, value)

```
SELECT ISNULL(is_discount, 0) AS result
```

is_discount 컬럼의 값이 NULL 이라면 0 을 출력한다.
NULL 이 아니라면 is_discount 의 값을 출력한다.


## CASE WHEN
CASE value 혹은 조건 WHEN value1 THEN result1 WHEN value2 THEN result2 … [ELSE else_result] END

```
SELECT
	CASE
		WHEN permission_type_id = 1
		THEN '관리자'
		WHEN permission_type_id = 2
		THEN '판매자'
		ELSE '일반 유저'
END	
```

WHEN 과 THEN 은 쌍을 이루어 사용해야 한다.
WHEN 조건 혹은 값 THEN 은 여러 번 사용할 수 있으며, 마지막 ELSE 는 모든 조건이 아닐 때 출력되는 값을 지정한다. Java 나 JavaScript 의 switch case 문이라고 보면 된다. SQL 에서는 SELECT 절에 들어갈 수도 있고, FROM 절 혹은 WHERE 절에 들어갈 수도 있다.

## NVL
NVL(value1, value2)

```
SELECT
	NVL(user_name, 'no name') from users
```

user_name 컬럼 값이 NULL 이면 'no name' 을 출력하고, NULL이 아니라면 user_name 컬럼 값을 출력한다.

