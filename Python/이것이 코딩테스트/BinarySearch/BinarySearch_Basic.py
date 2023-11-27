# 이진 탐색 시간복잡도는 O(logN)
# 이진 탐색 문제는 탐색 범위가 큰 상황에서의 탐색을 가정하는 경우가 많다
# 탐색 범위가 2000만 을 넘어가면 이진탐색으로 접근해보길 권유
# 이진 탐색의 조건은 '데이터 정렬' 이다.


# 이진 탐색 -> 재귀 함수
def binary_search(arr,target,start,end):
    if start > end:
        return None
    mid = (start + end) // 2
    if arr[mid] == target:
        return mid
    #중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    elif arr[mid] > target:
        return binary_search(arr,target,start,mid-1)
    else:
        return binary_search(arr,target,mid+1,end)
    
# 이진 탐색 --> 반복문
def binary_search(arr,target,start,end):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None