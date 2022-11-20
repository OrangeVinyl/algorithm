m = int(input())
n = int(input())
sosu_list = []

for i in range(m,n+1):
    not_sosu = 0
    if i>1:
        for j in range(2,i):
            if i % j == 0:
                not_sosu += 1
                break
        if not_sosu == 0:
            sosu_list.append(i)

if len(sosu_list)>0:
    print(sum(sosu_list))
    print(min(sosu_list))
else:
    print(-1)