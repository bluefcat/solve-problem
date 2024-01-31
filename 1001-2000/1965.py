import sys
import bisect
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
idx = [0 for _ in l]
cache = [] 

for i, x in enumerate(l):
    t = bisect.bisect_left(cache, x) 
    if t >= len(cache):
       cache.append(x)
    else:
        cache[t] = x 
    idx[i] = t+1

print(max(idx))
