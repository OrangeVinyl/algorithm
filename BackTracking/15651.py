n,m = map(int,input().split())
arr = []

def dfs():
    if len(arr) == m:
        print(' '.join(map(str,arr)))
        
    
    for i in range(1,n+1):
        if len(arr) == m:
            continue
        arr.append(i)
        dfs()
        arr.pop()
        
dfs()