import sys
input = sys.stdin.readline

n = int(input())
l = [list(map(int, input().split(" "))) for _ in range(n)]

cache = [[0 for _ in range(n+2)] for _ in range(n+1)]

for task in range(1, n+1):
    # task is start task day and task idx
    t, p = l[task-1]
    for day in range(1, n+2):
        cache[task][day] = max(
            cache[task-1][day],
            cache[task][day-1]
        )
        if task + (t-1) <= day:
            cache[task][day] = max(
                cache[task][day],
                cache[task-1][day-t] + p
            )


for c in cache:
    print(c)

print(cache[n][n])
