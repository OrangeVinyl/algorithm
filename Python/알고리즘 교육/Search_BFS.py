# 문제 해결 아이디어

# 큐에 현재 노드의 번호를 삽입한다.
# 현재 노드를 방문처리한다.
# 큐에서 노드 번호를 꺼낸 뒤,
# 해당 노드 번호를 출력하고,
# 해당 노드의 모든 인접 노드에 대해서,
# 방문하지 않았다면,
# 큐에 해당 노드 번호를 넣고,
# 해당 노드를 방문처리한다.
# 3~5의 과정을 큐에 데이터가 없을때 까지 계속 반복한다.
from collections import deque

def bfs(graph,start,visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v,end = " ")
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
                
                
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