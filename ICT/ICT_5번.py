work_hours = int(input())
day_hours = int(input())
pattern = list(input())

def findSchedules(work_hours, day_hours, pattern):
        schedule = [int(c) if c != '?' else -1 for c in pattern]
        schedules = []
        n = len(schedule)
    
        def dfs(idx, total, schedule):
            if idx == n:
                if total == work_hours:
                    schedules.append(schedule[:])
                return
    
            if schedule[idx] != -1:
                dfs(idx + 1, total + schedule[idx], schedule)
                return
    
            for i in range(day_hours + 1):
                schedule[idx] = i
                dfs(idx + 1, total + i, schedule)
                schedule[idx] = -1
    
        dfs(0, 0, schedule)
        
        for s in schedules:
            print("".join(map(str,s)))
    
findSchedules(work_hours, day_hours, pattern)