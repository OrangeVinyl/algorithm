n,m = map(int,input().split())
arr = []

def dfs(start):
    if len(arr) == m:
        print(' '.join(map(str,arr)))
        
    
    for i in range(start,n+1):
        if i in arr:
            continue
        arr.append(i)
        dfs(i+1)
        arr.pop()
        
dfs(1)