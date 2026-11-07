import sys
from itertools import product

input = sys.stdin.readline
MOD = 1_000_000_007

t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())
    result = 0

    result = (min(b, c) + (a-1)) % MOD

    print(result)
