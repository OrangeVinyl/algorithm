cnt = int(input())

for _ in range(cnt):
    arr = list(map(int,input().split()))
    avg = sum(arr[1:]) / arr[0]
    n = 0
    for score in arr[1:]:
        if score > avg:
            n += 1
    result = n / arr[0] * 100
    print("{0:.3f}%".format(result))
    