import sys
from collections import Counter

input = sys.stdin.readline
r, c = map(int, input().strip().split())
n = int(input().strip())
h = list(map(int, input().strip().split()))
count = Counter(h)

for x in count:
    count[x] = min(count[x], c)

l = sorted(count.elements())
result = sum(len(l[i*c:(i+1)*c]) for i, _ in enumerate(l[::min(c,r)]))
print(result)