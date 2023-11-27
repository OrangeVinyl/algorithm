N = int(input())

before = list(map(int,input()))
target = list(map(int,input()))
# cnt = 0
# temp_before = before[:] #리스트 슬라이싱을 이용한 깊은 복사



# #첫 번째를 안 누른 경우
# for i in range(1, N):
#     if before[i-1] != target[i-1]:
#         cnt += 1
#         before[i] = 1 - before[i]
#         before[i-1] = 1 - before[i]
#         # i의 범위는 (1<i<N)
#         if i != N-1:
#             before[i+1] = 1 - before[i+1]
# else:
#     if before == target:
#         print(cnt)
#         exit()

# #첫 번째를 누른 경우
# cnt = 1
# temp_before[0] = 1 - temp_before[0]
# temp_before[1] = 1 - temp_before[1]

# for i in range(1,N):
#     if temp_before[i-1] != target[i-1]:
#         cnt += 1
#         temp_before[i] = 1 - temp_before[i]
#         temp_before[i] = 1 - temp_before[i-1]
#         #마찬가지다
#         if i != N-1:
#             temp_before[i+1] = 1 - temp_before[i+1]           
# else:
#     if temp_before == target:
#         print(cnt)
#         exit()

# #불가능한 경우            
# print(-1)

def change(before, target):
    temp_before = before[:]
    cnt = 0
    for i in range(1,N):
        if temp_before[i-1] == target[i-1]:
            continue
        cnt += 1
        for j in range(i-1,i+2):
            if j < N:
                temp_before[j] = 1 - temp_before[j]
    return cnt if temp_before == target else 1e9
    
#첫 번째를 누르지 않은 경우
result = change(before, target)
#첫 번째를 누른 경우
before[0] = 1 - before[0]
before[1] = 1 - before[1]
result = min(result, change(before, target) + 1) #두 가지의 결과값을 비교하여 최솟값 저장
print(result if result != 1e9 else -1) #두 가지 경우 모두 충족 못하는 경우를 고려한 삼항연산자