N,M = map(int,input().split())
x,y,direction = map(int,input().split())
d = [[0] * M for _ in range(N)] #가본곳을 체크하기 위해 NxM 영역을 0으로 초기화
d[x][y] = 1 #현재 좌표 방문 처리

array = []
for i in range(N):
    array.append(list(map(int,input().split())))
    
dx = [-1,0,1,0]
dy = [0,1,0,-1]
    
def turn_left():
    global direction #global을 사용하는 이유는 함수 밖에서 선언한 전역변수이기 때문
    direction -= 1
    if direction == -1:
        direction = 3
    

cnt = 1
turn_count = 0
while True:
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    #가보지 않은 경우일 때(전진할 경우)
    if d[nx][ny] == 0 and array[nx][ny] == 0:
        d[nx][ny] = 1
        x = nx
        y = ny
        cnt += 1
        turn_count = 0
        continue
    #가지 못하는 경우(이미 가본칸이거나 바다로 되어 있을 경우)
    else:
        turn_count += 1
    #네 방향 모두 가지 못하는 경우
    if turn_count == 4:
        nx = x - dx[direction]
        ny = y - dy[direction]
        #뒤로 갈 수 없는 경우(바다인 경우)
        if array[nx][ny] == 0:
            x = nx
            y = ny
        #뒤로 갈 수 있는 경우
        else:
            break
        turn_time = 0

print(cnt)
        
        
        