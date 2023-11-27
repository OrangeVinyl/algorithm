week_list = ['MON','TUE','WED','THU','FRI','SAT','SUN']
month_list = [0,31,28,31,30,31,30,31,31,30,31,30,31]

x,y = map(int,input().split())
total = 0
for i in range(x):
    total += month_list[i]
total += y 

print(week_list[(total % 7)-1])