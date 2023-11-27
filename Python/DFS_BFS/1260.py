from collections import deque

N, M, V = map(int,input().split())
graph = [[] for _ in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in graph:
    i.sort()

visited_dfs = [False] * (N+1)
visited_bfs = [False] * (N+1)

def DFS(graph,v,visited_dfs):
    visited_dfs[v] = True
    print(v, end=' ')

    for i in graph[v]:
        if not visited_dfs[i]:
            DFS(graph,i,visited_dfs)

def BFS(graph,start,visited_bfs):
    queue = deque([start])
    visited_bfs[start] = True
    
    while queue:
        v = queue.popleft()
        print(v, end = ' ')
        for i in graph[v]:
            if not visited_bfs[i]:
                queue.append(i)
                visited_bfs[i] = True

DFS(graph,V,visited_dfs)
print()
BFS(graph,V,visited_bfs)