import sys 
from datetime import datetime
input = sys.stdin.readline 



def pi(n, i, tn: datetime, ti: datetime):
    d = ((tn-ti).total_seconds())/(24*60)
    return round(max(0.5**(d/365), 0.9**(n-i)))

N = int(input())
score = [input().strip().split() for _ in range(N)]

if N == 0:
    print(0)
    exit(0)

for i, (x, y, z) in enumerate(score):
    score[i] = [datetime.strptime(f"{x} {y}", "%Y/%m/%d %H:%M:%S"), int(z)]

tier = [y*pi(N, i+1, score[-1][0], x) for i, (x, y) in enumerate(score)]
c = [pi(N, i+1, score[-1][0], x) for i, (x, _) in enumerate(score)]
print(round(sum(tier)/sum(c)))
