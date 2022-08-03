cnt = int(input())
for _ in range(cnt):
    num,word = input().split()
    for i in word:
        print(i*int(num),end="")
    print()