# 선택 정렬 --> 비효율작이나 작성할 줄은 알아야 한다.
arr = []
for i in range(len(arr)):
    min_index = i
    for j in range(i+1, len(arr)):
        if arr[min_index] > arr[j]:
            min_index = j
    arr[i],arr[min_index] = arr[min_index],arr[i]
print(arr)

# 삽입 정렬 --> 거의 다 정렬이 되어있을 때 유리하다.
arr = []
for i in range(i+1,len(arr)):
    for j in range(i,0,-1):
        if arr[j] < arr[j-1]:
            arr[j],arr[j-1] = arr[j-1], arr[j]
        else:
            break

# 퀵 정렬 --> 피벗을 정한다. 왼쪽에서부터는 피벗보다 큰 수, 오른쪽에서부터는 피벗보다 작은 수
# 교차하는 경우 종료. 단 '작은 데이터'와 피벗을 교체 
# 재귀를 사용하며 현재 리스트의 데이터 개수가 1개인 경우 종료.

arr = []
def quick_sort(arr,start,end):
    # 원소가 1개인 경우
    if start >= end:
        return
    pivot = start
    left = start + 1
    right = end
    while left <= right:
        #피벗보다 큰 데이터를 찾을때까지 반복
        while left <= end and arr[left] <= arr[pivot]:
            left += 1
        #피벗보다 작은 데이터를 찾을때까지 반복
        while right > start and arr[right] > arr[pivot]:
            right -= 1
        #엇갈렸다면 작은데이터와 피벗을 교체
        if left > right:
            arr[right], arr[pivot] = arr[pivot], arr[right]
        #엇갈리지 않았다면 않았다면 작은데이터와 큰 데이터 교체
        else:
            arr[right], arr[left] = arr[left], arr[right]
    quick_sort(arr,start, right-1)
    quick_sort(arr,right+1,end)

quick_sort(arr,0,len(arr)-1) #-1의 경우 피벗을 제외하기 위해서

#파이썬의 장점을 살린 퀵 정렬 소스코드
arr = []
def quick_sort(arr):
    #리스트가 하나 이하의 원소만을 담고 있다면 종료
    if len(arr) <= 1:
        return arr
    
    pivot = arr[0]
    tail = arr[1:] #피벗을 제외한 리스트
    
    left_side = [x for x in tail if x<= pivot] #분할된 왼쪽 부분
    right_side = [x for x in tail if x > pivot] #분할된 오른쪽 부분
    
    return quick_sort(left_side) + [pivot] + quick_sort(right_side)
print(quick_sort(arr))

# 계수 정렬 --> 특정한 조건이 부합할 때만 사용할 수 있지만, 매우 빠른 알고리즘 
# 데이터의 크기 범위가 제한되어 정수 형태로 표현할 수 있을 때만!
# 모든 범위를 담을 수 있는 크기의 리스트를 선언해야 한다! -> 가장 큰 데이터와 가장 작은 데이터의 차이가 큰 경우에는 사용하지 않는 것이 좋다.
# 시간 복잡도  O(N+K)
arr = []
count = [0] * (max(arr)+1)

for i in range(len(arr)):
    count[arr[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i)

#Sort 함수는 시간복잡도가 O(NlogN)이다.
    