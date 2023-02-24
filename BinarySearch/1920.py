n = int(input())
A = sorted(list(map(int,input().split())))
m = int(input())
m_list = list(map(int,input().split()))


# 틀린 풀이
# for i in range(m):
#     if m_list[i] in A:
#         print(1)
#     else:
#         print(0)

def binary_search(arr,target,start,end):
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return 1
        elif arr[mid] > target:
            end = mid -1 
        else:
            start = mid + 1
    return 0


for i in m_list:
    print(binary_search(A,i,0,n-1))