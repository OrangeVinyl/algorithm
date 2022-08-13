total = int(input())
numbers = map(int,input().split())
sosu = 0
for num in numbers:
    not_sosu = 0
    if num > 1:
        for i in range(2,num):
            if num % i == 0:
                not_sosu += 1
        if not_sosu == 0:
            sosu += 1
print(sosu)
            
