from collections import deque
n = int(input())
house = [list(map(int,input())) for _ in range(n)]
result = []
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(house,x,y):
    queue = deque()
    queue.append((x,y))
    house[x][y] = 0
    cnt = 1
    
    while queue:
        x,y = queue.popleft()
        house[x][y] = 0        
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if house[nx][ny] == 1:
                house[nx][ny] = 0
                queue.append((nx,ny))
                cnt += 1
                
    return cnt

for i in range(n):
    for j in range(n):
        if house[i][j] == 1:
            cnt = bfs(house,i,j)
            result.append(cnt)
        
result.sort()

print(len(result))
for i in result:
    print(i)