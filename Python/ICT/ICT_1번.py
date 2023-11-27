def getGroupedAnagrams(words):
    dic = {}
    for anagram in words:
        key = "".join(sorted(anagram))
        
        if key not in dic.keys():
            dic[key] = [anagram]
        else:
            dic[key].append(anagram)
    print(len(list(dic.values())))
    

n = int(input())    
words = []
for _ in range(n):
    words.append(input())
getGroupedAnagrams(words)