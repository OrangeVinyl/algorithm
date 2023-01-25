from collections import deque

visited = [False] * 9

graph = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

def BFS(graph, start, visited):
    queue = deque([start])
    
    #현재 노드 방문 처리
    visited[start] = True
    
    #큐가 빌 때까지 반복
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

BFS(graph, 1, visited)