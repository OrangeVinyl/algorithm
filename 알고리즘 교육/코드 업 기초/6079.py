a = int(input())
result = 0

for i in range(1,a+1):
    result += i 
    if result >= a:
        print(i)
        break