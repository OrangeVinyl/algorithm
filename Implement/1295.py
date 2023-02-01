testcase_list =[]

while True:
    testcase = input()
    if testcase == '0':
        break
    testcase_list.append(testcase)

for test in testcase_list:
    reverseTest =  test[::-1]
    if reverseTest == test:
        print('yes')
    else:
        print('no')