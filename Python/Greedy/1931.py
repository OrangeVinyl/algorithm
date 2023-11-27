n = int(input())
room = []


for i in range(n):
    start, end = map(int,input().split())
    room.append([start,end])

room.sort(key = lambda x : x[0])
room.sort(key = lambda x : x[1])

last = room[0][1] #마지막 회의시간 
cnt = 1 #결과값

for x in range(1,n):
    if room[x][0] >= last:
        cnt += 1
        last = room[x][1]

print(cnt)