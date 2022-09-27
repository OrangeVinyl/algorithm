import sys
n,k = map(int,sys.stdin.readline().split())
score_list = list(map(int,sys.stdin.readline().split()))
score_list.sort(reverse=True)
print(score_list[k-1])