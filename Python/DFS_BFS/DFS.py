#DFS
visited = [False] * 9

#연결된 노드들에 대한 정보
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

def DFS(graph, v, visited):
    # 노드를 방문처리 해준다
    visited[v] = True
    print(v, end =' ')
    
    for i in graph[v]:
        if not visited[i]:
            DFS(graph,i,visited)
            
DFS(graph,1,visited)

