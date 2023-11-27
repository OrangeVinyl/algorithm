from math import sqrt
import sys

def is_prime(num):
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for j in range(2,int(sqrt(num)+1)):
        if num % j == 0:
            return False
    return True

while True:
    n = int(sys.stdin.readline())
    
    if n == 0:
        break
    prime_cnt = 0 
    
    for i in range(n+1,(2*n)+1):
        if is_prime(i):
            prime_cnt += 1
        
    print(prime_cnt)

    