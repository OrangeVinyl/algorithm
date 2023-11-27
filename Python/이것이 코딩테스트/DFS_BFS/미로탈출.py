from collections import deque

n,m = map(int,input().split())
maze = [list(map(int,input())) for _ in range(n)]

#이동 방향 상,하,좌,우
dx = [-1,1,0,0]
dy = [0,0,-1,1]


def BFS(x,y):
    queue = deque()
    queue.append((x,y))
    
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if maze[nx][ny] == 0:
                continue
            
            # 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
            if maze[nx][ny] == 1:
                maze[nx][ny] = maze[x][y] + 1
                queue.append((nx,ny))

    # 가장 오른쪽 아래까지의 최단 거리 반환
    return maze[n-1][m-1]

print(BFS(0,0))