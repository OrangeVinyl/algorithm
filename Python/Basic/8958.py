cnt = int(input())
for _ in range(cnt):
    ox_list = list(input())
    score = 0
    sum_score = 0 #새로운 리스트 받을 때  점수 초기화
    for ox in ox_list:
        if ox == 'O':
            score += 1
            sum_score += score
        else:
            score = 0
    print(sum_score)