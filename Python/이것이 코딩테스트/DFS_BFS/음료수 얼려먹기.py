n,m = map(int,input().split())
ice = [list(map(int,input())) for _ in range(n)]

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def DFS(x,y):
    if x < 0  or x>=n or y < 0 or y >= m:
        return False
    if ice[x][y] == 0:
        ice[x][y] = 1
        for i in range(4):
            x += dx[i]
            y += dy[i]
            DFS(x,y)
        return True
    return False

result = 0
for a in range(n):
    for b in range(m):
        if DFS(a,b):
            result += 1

print(result)

