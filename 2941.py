cro_alpha = ['c=','c-','dz=','d-','lj','nj','s=','z=']
alpha = input()

for x in cro_alpha:
    alpha = alpha.replace(x,'*')
print(len(alpha)) 