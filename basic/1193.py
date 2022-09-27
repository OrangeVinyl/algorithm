# num = int(input())
# line_num = 0
# sum = 0

# while num > sum:
#     line_num +=1 
#     sum += line_num

# n = sum - num




# if line_num % 2 == 0:
#     print("{0}/{1}".format(n+1,line_num-n))
# else:
#     print("{0}/{1}".format(line_num-n,n+1))

n = int(input())
line = 0
end = 0
while n > end:
    line += 1
    end += line

x = end - n 
if line % 2 ==0:
    top = line - x
    bottom = x + 1
else:
    top = x+1
    bottom = line - x
print("{0}/{1}".format(top,bottom))