def recursive_dfs(graph,v,visited):
    visited[v] = True
    print(v, end= " ")
    for i in graph[v]:
        if not visited[i]:
            recursive_dfs(graph,i,visited)
    
    
graph = [
    [], # 0번째 노드는 인덱싱을 위해 삽입
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

visited = [False] * len(graph)
recursive_dfs(graph,1,visited)

