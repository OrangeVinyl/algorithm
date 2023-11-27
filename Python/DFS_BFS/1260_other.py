from collections import deque

N,M,V = map(int,input().split())
graph = [[0] * (N+1) for _ in range(N+1)]

visited_dfs = [0] * (N+1)
visited_bfs = [0] * (N+1)

for i in range(M):
    a,b = map(int,input().split())
    graph[a][b] = graph[b][a] = 1

def DFS(V):
    visited_dfs[V] = 1
    print(V, end = ' ')
    
    for i in range(1,N+1):
        if(visited_dfs[i] == 0 and graph[V][i] == 1):
            DFS(i)

def BFS(V):
    queue = deque([V])
    visited_bfs[V] = 1
    
    while queue:
        V = queue.popleft()
        print(V, end = ' ')
        for i in range(1,N+1):
            if(visited_bfs[i] == 0 and graph[V][i] == 1):
                queue.append(i)
                visited_bfs[i] = 1
                
DFS(V)
print()
BFS(V)