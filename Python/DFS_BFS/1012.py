from collections import deque

#테스트 케이스
t = int(input())

dx = [1,-1,0,0]
dy = [0,0,-1,1]

def BFS(x,y):
    queue = deque([(x,y)])
    #인접한 배추 0 변환
    ground[x][y] = 0 
    
    while queue:
        x,y = queue.popleft()
        
        for i in range(len(dx)):
            nx = x + dx[i]
            ny = y + dy[i]
            
            #밭을 벗어나는 경우
            if nx < 0 or nx >=m or ny <0 or ny>=n:
                continue
            if ground[nx][ny] == 1:
                ground[nx][ny] = 0
                queue.append((nx,ny))

for i in range(t):
    # m = 가로길이 n = 세로길이 k = 배추 심은 갯수(위치)
    m,n,k = map(int,input().split())
    ground = [[0]*n for _ in range(m)]
    cnt = 0
    

    for j in range(k):
        x,y = map(int,input().split())
        ground[x][y] = 1

    for a in range(m):
        for b in range(n):
            if ground[a][b] == 1:
                BFS(a,b)
                cnt += 1
    print(cnt)
