n = int(input())
a = sorted(list(map(int,input().split())))
m = int(input())
b = list(map(int,input().split()))

def binary_search(array, target, start, end):
    if start > end:
        return None
    mid =  (start + end) // 2
    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return binary_search(array,target,start,mid-1)
    else:
        return binary_search(array,target,mid+1,end)

for com in b:
    if binary_search(a,com,0,n-1) == None:
        print('No', end='')
    else:
        print('Yes', end='')
    
