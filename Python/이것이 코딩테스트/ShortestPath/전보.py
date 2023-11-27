"""
일방향

- 받게 되는 도시의 총 개수
- 도시들이 모두 메시지를 받는데까지 걸리는 시간은?

"""
import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)
n,m,start = map(int,input().split())
graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    x,y,z = map(int,input().split())
    graph[x].append((y,z))
    
def dijkstra(start):
    q = []
    heapq.heappush(q,(start,0))
    distance[start] = 0
    
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
                
dijkstra(start)

count = 0
max_distance = 0

for t in distance:
    if t != INF:
        count += 1
        max_distance = max(max_distance, t)

print(count- 1, max_distance)