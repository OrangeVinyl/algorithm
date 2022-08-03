t = int(input())

for i in range(t):
    h,w,g = map(int,input().split())
    floor = 0
    room = 0
    if g % h != 0:
        room = int(g/h)+1
        floor = int(g%h)*100
    else:
        room = int(g/h)
        floor = h*100
    print(floor+room)




# 6/12 25번째 손님이 있으면 어떻게 할 것인가?
# g/h 의 몫은 w를 결정한다. 단 g/h의 나머지가 영이라면 +1 안해도 된다.
# 나머지 같은 경우에는 층수에 해당한다. 