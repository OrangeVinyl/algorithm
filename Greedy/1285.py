N = int(input())
coin = [list(input()) for _ in range(N)]
result = N*N + 1

for bit in range(1 << N):
    #리스트 복사
    tmp_lst = [coin[i][:] for i in range(N)]
    for i in range(N):
        if bit & (1 << i): #비트 마스킹에 해당하면
            for j in range(N):
                if tmp_lst[i][j] == 'H':
                    tmp_lst[i][j] = 'T'
                else:
                    tmp_lst[i][j] = 'H'
    tcnt = 0
    for i in range(N):
        cnt = 0
        for j in range(N):
            if tmp_lst[j][i] == 'T':
                cnt += 1
        tcnt += min(cnt, N-cnt)
    result = min(result, tcnt)
    
print(result)