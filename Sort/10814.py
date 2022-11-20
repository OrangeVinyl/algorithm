import sys

n = int(sys.stdin.readline())
ls = []

for _ in range(n):
    age , name = map(str,input().split())
    age = int(age)
    ls.append((age,name))
    
ls.sort(key = lambda x : x[0]) #ls의 내용 중 age로만 판별한다.

for i in ls:
    print(i[0],i[1])