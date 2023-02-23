n = int(input())
A = list(map(int,input().split()))
m = int(input())
m_list = list(map(int,input().split()))

for i in range(m):
    if m_list[i] in A:
        print(1)
    else:
        print(0)