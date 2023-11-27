import time

n = int(input())
start_time = time.time()

total = 0

coin_list  = [500, 100, 50, 10]

for coin in coin_list:
    total += n // coin
    n = n % coin
    
print(total)

end_time = time.time()
print(f"{end_time-start_time:.5f} sec")