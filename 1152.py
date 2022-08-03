# 첫 번째가 공백인지 아닌지 판별해야 한다.
# 공백이라면 공백 후 바로 뒤부터 +1
# 공백이 아니라면 +1을 해놓은 상태에서 공백 찾기

# sent = input()
# cnt = 0

# if sent[0] == " ":
#     cnt = sent.count(" ")
# else:
#     cnt = 1
#     cnt += sent.count(" ")
# print(cnt)

word = input().split()
print(len(word))