coordinate = input()
row = int(coordinate[1])
column = int(ord(coordinate[0]) - int(ord('a')) + 1)

steps = [(-2,-1), (-1,-2), (1,-2), (2,-1), (2,1), (1,2), (-1,2), (-2,1)]

result = 0

for step in steps:
    next_row = row + step[0]
    next_column = column + step[1]
    if next_row in range(1,9) and next_column in range(1,9):
        result += 1

print(result)