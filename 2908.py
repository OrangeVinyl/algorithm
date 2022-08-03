# a,b = map(int,input().split())

# num_1 = list(str(a))
# num_2 = list(str(b))
# num_1.reverse()
# num_2.reverse()

# num1 = int(''.join(num_1))
# num2 = int(''.join(num_2))

# if num1 > num2:
#     print(num1)
# else:
#     print(num2)

num1, num2 = input().split()
num1 = int(num1[::-1])  # [::-1] : 역순
num2 = int(num2[::-1])

if num1 > num2:
    print(num1)
else :
    print(num2)