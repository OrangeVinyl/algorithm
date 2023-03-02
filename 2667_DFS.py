n = int(input())
house = [list(map(int,input())) for _ in range(n)]
result = []

dx = [-1,1,0,0]
dy = [0,0,-1,1]

cnt = 0
result = []

def dfs(x,y):
    if x < 0 or x >= n or y < 0 or y >= n:
        return 

    if house[x][y] == 1:
        global cnt
        cnt += 1
        house[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx,ny)


for i in range(n):
    for j in range(n):
        if house[i][j] == 1:
            dfs(i,j)
            result.append(cnt)
            cnt = 0

print(len(result))            
for i in result:
    print(i)