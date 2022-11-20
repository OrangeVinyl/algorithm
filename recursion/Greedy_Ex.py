n = int(input())
total = 0

coin_list  = [500, 100, 50, 10]

for coin in coin_list:
    total += n // coin
    n = n % coin
    
print(total)