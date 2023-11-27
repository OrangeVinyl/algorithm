import heapq

N = int(input())
pay_list = [list(map(int,input().split())) for _ in range(N)]
pay_list.sort(key = lambda x:x[1])

q_list = []
for i in pay_list:
    heapq.heappush(q_list, i[0])
    if (len(q_list) > i[1]):
        heapq.heappop(q_list)
print(sum(q_list))