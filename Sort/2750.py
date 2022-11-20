import sys

n = int(sys.stdin.readline())
m = []

for i in range(n):
    m.append(int(sys.stdin.readline()))

m.sort()
for i in range(len(m)):
    print(m[i])