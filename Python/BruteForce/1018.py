n,m = map(int,input().split())
board = [input() for _ in range(n)]


count_list = []

for i in range(n-7):
    for j in range(m-7):
        aCase = 0
        bCase = 0
        for a in range(i,i+8):
            for b in range(j,j+8):
                if (a+b) % 2 == 0:
                    if board[a][b] != 'W':
                        aCase += 1
                    if board[a][b] != 'B':
                        bCase += 1
                else:
                    if board[a][b] != 'B':
                        aCase += 1
                    if board[a][b] != 'W':
                        bCase += 1
        count_list.append(min(aCase,bCase))

print(min(count_list))
