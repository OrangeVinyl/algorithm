import sys

n = int(sys.stdin.readline())
word_list = []

for _ in range(n):
    word_list.append(sys.stdin.readline().strip())
    
word_list = list(set(word_list)) # 중복제거 및 데이터 타입 선정
word_list.sort()
word_list.sort(key = lambda x:len(x)) #사전식으로 정렬

for i in word_list:
    print(i)




#정렬 순서는 상위 조건 A, 하위 조건 B가 있으면 하위 조건 B를 하고 상위 조건 A를 충족시키자.
##중복값 제거는 set()으로 한다.
### strip() = 문자열에서 특정 문자를 제거 - 인자가 따로 없으면 공백 제거
#### sort(), sorted() 함수 둘 다 매개변수로 key, reverse를 가지고 있다. key 같은 경우, lambda 함수를 사용할 수 있는데, ex) sort(key = lambda x:x[0])