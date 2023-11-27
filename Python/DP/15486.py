n = int(input())
dp = [0] * (n+1)
t_list = [0] * (n+1)
p_list = [0] * (n+1)

for i in range(1,n+1):
    Ti, Pi = map(int,input().split())
    t_list[i] = Ti
    p_list[i] = Pi

for i in range(1,n+1):
    dp[i] = max(dp[i-1],dp[i])
    last_date = i + t_list[i] -1
    if last_date <= n:
        dp[last_date] = max(dp[last_date], dp[i-1] + p_list[i])
        
print(max(dp))