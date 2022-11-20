#Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
#즉 Xi가 리스트 안에서의 크기 순서를 출력하라는 소리다. (크기 순서는 0부터 시작한다.)
#결국 리스트 안에서의 자기보다 작은 숫자의 개수를 세는 것이다.

# n = int(input())
# ls = list(map(int,input().split()))


# ls_final = sorted(list(set(ls)))

# for i in ls:
#     print(ls_final.index(i), end=" ")

n = int(input())
ls = list(map(int,input().split()))


ls_final = sorted(list(set(ls)))
dic = {ls_final[i] : i for i in range(len(ls_final))} #Comprehension 참조
for i in ls:
    print(dic[i], end =" ") #이 부분이 아직은 좀 이해가 안됨.

