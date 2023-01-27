n = list(input())
n.sort(reverse = True)
sum = 0

for i in n:
    sum += int(i)
    
if '0' in n and sum % 3 ==0:
    print(''.join(n))
else:
    print()