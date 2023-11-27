#이코테 DP_예제_효율적인 화폐구성

n,m = map(int,input().split())
current_list = []
for i in range(n):
    current_list.append(int(input()))

dp = [10001] * (m+1)
dp[0] = 0

for i in current_list:
    for j in range(i,m+1):
        if dp[j-i] != 10001:
            dp[j] = min(dp[j], dp[j-i]+1)

if dp[m] == 10001:
    print(-1)
else:
    print(dp[m])