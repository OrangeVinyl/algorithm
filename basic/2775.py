t = int(input())

for _ in range(t):
    floor = int(input())
    num = int(input())
    floorZ =  [x for x in range(1,num+1)]
    for k in range(floor):
        for n in range(1,num):
            floorZ[n] += floorZ[n-1]
    print(floorZ[-1])