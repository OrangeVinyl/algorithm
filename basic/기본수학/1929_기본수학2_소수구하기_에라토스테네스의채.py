import sys

m,n=map(int,sys.stdin.readline().split())
sosu_list = []

for num in range(m,n+1):
    condition = True
    if num == 1:
        continue
    for i in range(2,int(num**0.5)+1):
        if num % i == 0:
            condition = False
            break
    if condition:
        sosu_list.append(num)
print(*sosu_list, sep="\n") #list 앞에 * 같은 경우는 리스트 언패킹이라고 생각하면 된다.
#에라토스테네스의 채