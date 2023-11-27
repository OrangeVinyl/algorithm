from math import sqrt

def is_prime(num):
    if num == 1:
        return False
    for j in range(2,int(sqrt(num)+1)):
        if num % j == 0:
            return False
    return True
        

for _ in range(int(input())):
    n = int(input())
    a,b = n // 2, n // 2
    while a>0:
        if is_prime(a) and is_prime(b):
            print(a,b)
            break
        else:
            a -= 1
            b += 1