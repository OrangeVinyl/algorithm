import heapq

N,K = map(int,input().split())
gem = sorted([list(map(int,input().split())) for _ in range(N)])
bags_weight = sorted([int(input()) for _ in range(K)])
tmp = []
result = 0

for bag in bags_weight:
    while gem and bag >= gem[0][0]:
        heapq.heappush(tmp, -gem[0][1]) # tmp에 보석 가격 입력
        heapq.heappop(gem) #입력값 제거
    
    #tmp에 요소가 있으면
    if tmp:
        result -= heapq.heappop(tmp)

print(result)

