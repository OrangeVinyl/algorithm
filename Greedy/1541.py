exp = input().split('-')
num = []

for i in exp:
    cnt = 0
    addition = i.split('+')
    for j in addition:
        cnt += int(j)
    num.append(cnt)

sum = num[0]
for s in range(1,len(num)):
    sum -= num[s]

print(sum)