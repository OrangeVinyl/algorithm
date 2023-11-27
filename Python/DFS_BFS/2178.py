# 1 -> 이동할 수 있는 칸 / 0 -> 이동할 수 없는 칸
# 최소의 칸 수 구하기 
# 서로 인접한 칸만 갈 수 있다
from collections import deque
n,m = map(int,input().split())
maze = []

for i in range(n):
    maze.append(list(map(int,input())))

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x,y):
    queue = deque([(x,y)])
    
    while queue:
        x,y = queue.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx < 0 or nx >= n  or ny < 0 or ny >= m:
                continue
            if maze[nx][ny] == 0:
                continue
            if maze[nx][ny] == 1:
                maze[nx][ny] = maze[x][y] + 1
                queue.append((nx,ny))
                
    return maze[n-1][m-1]

print(bfs(0,0))