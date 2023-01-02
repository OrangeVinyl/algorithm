import sys
n = int(sys.stdin.readline())
time_list = list(map(int,sys.stdin.readline().split()))
sum = 0

time_list.sort()

for i in range(n):
    sum += time_list[i]*(n-i)

print(sum)

