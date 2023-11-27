from collections import deque

n,m = map(int,input().split())
graph = []
for i in range(n):
    graph.append(list(map(int,input())))

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    queue = deque()    
    queue.append((x,y))
    #현재 노드를 방문처리한다.
    while queue:
        x,y = queue.popleft()
    # 해당 노드의 모든 인접 노드에 대해서
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        #이동한 거리가 벗어나지 않았다면
        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue
        #괴물이 있는 경우
        if graph[nx][ny] == 0:
            continue  
        #괴물이 없는 경우 그리고 처음 방문하는 경우
        if graph[nx][ny] == 1:
            graph[nx][ny] = graph[x][y] + 1
            queue.append((nx,ny))
    return graph[n-1][m-1]        


print(bfs(0,0))
