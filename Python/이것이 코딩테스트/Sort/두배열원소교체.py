n,k = map(int,input().split())

a_list = sorted(list(map(int,input().split())))
b_list = sorted(list(map(int,input().split())), reverse=True)

for i in range(k):
    if a_list[i] >= b_list[i]:
        break
    else:
        a_list[i] = b_list[i]
print(sum(a_list))

