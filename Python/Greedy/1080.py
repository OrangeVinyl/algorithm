n,m = map(int,input().split())
A = [list(map(int,input().strip())) for _ in range(n)] #input().strip() and LC
B = [list(map(int,input().strip())) for _ in range(n)]
count = 0

def flip(i,j):
    for x in range(i,i+3):
        for y in range(j,j+3):
            A[x][y] = 1 - A[x][y]
    
def check():
    for i in range(n):
        for j in range(m):
            if A[i][j] != B[i][j]:
                return False
    return True
        

for i in range(n-2):
    for j in range(m-2):
        if A[i][j] != B[i][j]:
            flip(i,j)
            count += 1

if check():
    print(count)
else:
    print(-1)