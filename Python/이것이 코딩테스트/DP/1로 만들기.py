x = int(input())
d = [0] * 30001

#butom-up 
for i in range(2,x+1):
    d[i] = d[i-1] + 1
    
    