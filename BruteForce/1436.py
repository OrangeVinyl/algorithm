n = int(input())
cnt = 0
target = 666

while True:
    if '666' in str(target):
        cnt += 1
    if cnt == n:
        print(target)
        break
    target += 1
