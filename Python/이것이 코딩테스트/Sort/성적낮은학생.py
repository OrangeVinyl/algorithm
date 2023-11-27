n = int(input())
student_score = []

for _ in range(n):
    value = input().split()
    student_score.append((value[0], int(value[1])))

student_score.sort(key=lambda x: x[1])

for i in student_score:
    print(i[0], end=' ')
    
                        
