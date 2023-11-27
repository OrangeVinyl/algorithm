n,k = map(int,input().split())
sum = 0

a = list(map(int,input().split()))
b = list(map(int,input().split()))

a = sorted(a)
b = sorted(b,reverse=True)

for i in range(k):
    if a[i] > b[i]:
        break
    a[i],b[i] = b[i], a[i]
    
for i in range(len(a)):
    sum += a[i]

print(sum)