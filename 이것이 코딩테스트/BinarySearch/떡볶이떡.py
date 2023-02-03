n,m = map(int,input().split())
ricecake = list(map(int,input().split()))


start = 0
end = max(ricecake)
result = 0

while start <= end:
    mid = (start + end) // 2
    total = 0
    for x in ricecake:
        if x > mid:
            total += x - mid
    if total < m:
        end = mid - 1
    else:
        result = m
        start = mid + 1
        
print(result)