def maxEnergy(mat):
    n = len(mat)
    m = len(mat[0])
    dp = [[-100000 for j in range(m)] for i in range(n)]
    for j in range(m):
        dp[0][j] = 100 - mat[0][j]
    for i in range(1, n):
        for j in range(m):
            if j > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] - mat[i][j])
            dp[i][j] = max(dp[i][j], dp[i-1][j] - mat[i][j])
            if j < m - 1:
                dp[i][j] = max(dp[i][j], dp[i-1][j+1] - mat[i][j])
    return max(dp[n-1])

mat_rows = int(input().strip())
mat_colums = int(input().strip())

mat = []

for _ in range(mat_rows):
    mat.append(list(map(int,input().rstrip().split())))
    
result = maxEnergy(mat)
print(result)