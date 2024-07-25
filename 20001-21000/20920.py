import sys
from collections import Counter

input = sys.stdin.readline

N, M = map(int, input().strip().split())
word = [input().strip() for _ in range(N)]
word = [
    w for w in word if len(w) >= M
]

counter = Counter(word).items()
result = sorted(counter, key= lambda x: -len(x[0]))
result = sorted(result, key=lambda x: -x[1])

for x, _ in result:
    print(x)
