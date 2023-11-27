n = int(input())
travel = list(map(int,input().split()))
travel.sort()

count = 0
sum = 0 

for i in travel:
    sum +=1
    if sum == i:
        count += 1
        sum = 0 
print(count)


# [ 3 ,2, 1, 4, 3, 2, 1]
# [1, 1, 2, 2, 3, 3, 4]
