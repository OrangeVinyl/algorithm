import sys
from unittest import result

n,m,k = map(int,sys.stdin.readline().split())
data = list(map(int,input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

total = 0 

while True:
    for i in range(k):
        if m == 0:
            break
        total += first
        m -= 1
    if m == 0:
        break
    total += second
    m -= 1
        
print(total)
