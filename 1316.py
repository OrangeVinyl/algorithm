num = int(input())
total = num

for i in range(num):
    word = input()
    for x in range(0,len(word)-1):
        if word[i] == word[i+1]:
            pass
        elif word[i] in word[i+1:]:
            total -= 1
            break
print(total)
            
            
N = int(input())
result = N
for i in range(0,N):
    word=input()
    for j in range(0,len(word)-1):
        if word[j]==word[j+1]:
            pass
        elif word[j] in word[j+1:]:
            result-=1
            break
print(result)

