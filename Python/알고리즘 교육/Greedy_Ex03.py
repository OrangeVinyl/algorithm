n,m =  map(int,input().split())
result = 0

for i in range(n):
    data_list = list(map(int,input().split()))
    min_price = min(data_list)
    result = max(result, min_price)

print(result)
    
