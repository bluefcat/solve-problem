import sys
from datetime import timedelta

input = sys.stdin.readline

n, k = map(int, input().split())

k = timedelta(minutes=k)
end = [
    timedelta(hours=15),
    timedelta(hours=18),
    timedelta(hours=21),
]

queue = [
    timedelta(hours=15),
    timedelta(hours=18),
    timedelta(hours=21),
]

result = []

for d in range(n+1):
    for i, e in enumerate(end):
        queue[i] = e + d*k
        if queue[i].days + d == n:
            result.append(queue[i])

print(len(result))
for r in result:
    s = r.seconds
    hours = s // 3600 
    s = s - (hours * 3600)
    minutes = s // 60

    print('{:02}:{:02}'.format(int(hours), int(minutes)))