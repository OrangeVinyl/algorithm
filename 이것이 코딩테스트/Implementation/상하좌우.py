# N = int(input())
# move = list(map(str,input().split()))

# x,y = (1,1)


# for i in move:
#     if x == 1 and i == "U":
#         continue
#     elif y == 1 and i == "L":
#         continue
#     elif x == N and i == "D":
#         continue
#     elif y == N and i == "R":
#         continue
    
#     if i == "L":
#         y -= 1
#     elif i == "R":
#         y += 1
#     elif i == "U":
#         x -= 1
#     else:
#         x += 1


# print(x,y)

n = int(input())
roots = input().split()
x,y = 1,1

#L,R,U,D
dx = [0,0,-1,1]
dy = [-1,1,0,0]
move = ['L','R','U','D']


for root in roots: #이동 계획 하나씩 확인
    for i in range(len(move)): #이동 후 좌표 구하기
        if root == move[i]:
            nx = x + dx[i]
            ny = y + dy[i]
            
    if nx<1 or ny<1 or nx>n+1 or ny>n+1:
        continue #무시
    
    x,y = nx,ny #이동  
        
print(x,y)