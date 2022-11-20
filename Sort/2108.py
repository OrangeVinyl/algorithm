from collections import Counter


li = []
n = int(input())
for _ in range(n):
    li.append(int(input()))

#산술평균 // round() > 반올림
print(round(sum(li) /n))
#중앙값
li.sort()
print(li[n//2])
#최빈값 from collections import Counter, Counter().most_common()
cnt = Counter(li).most_common(2)
if len(li) > 1:
    if cnt[0][1] == cnt[1][1]:
        print(cnt[1][0])
    else:
        print(cnt[0][0])

#범위
print(max(li)-min(li))