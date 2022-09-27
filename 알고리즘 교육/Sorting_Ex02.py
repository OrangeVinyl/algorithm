n = int(input())
data = []

for i in range(n):
    input_data = input().split()
    data.append((input_data[0],int(input_data[1])))
    
data = sorted(data,key=lambda st:st[1])
for st in data:
    print(st[0], end=" ")