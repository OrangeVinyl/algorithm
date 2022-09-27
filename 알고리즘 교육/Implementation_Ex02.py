data_value = input()

row = int(data_value[1])
column = int(ord(data_value[0])) - int(ord('a')) + 1 #정수 a를 숫자 1로 변환 = a의 아스키코드 값을 빼고 + 1

movement = [
    (2,1), (2,-1), (-2,1), (-2,-1),
    (1,2), (1,-2), (-1,2), (-1,-2)
]

n_row = 0
n_column = 0

total = 0 
for move in movement:
    n_row = row + move[0]
    n_column = column + move[1]
    if n_row < 1 or n_column < 1 or n_row >8 or n_column > 8:
        continue
    total += 1

print(total)