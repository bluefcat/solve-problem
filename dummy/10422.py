import sys
input = sys.stdin.readline

L = 5001
P = 1000000007

cache = [0 for _ in range(L)]
symmetry = [0 for _ in range(L)]

cache[0], symmetry[0] = 1, 0
cache[2], symmetry[2] = 1, 1


for i in range(4, L)[::2]:
    result = cache[i-2]

    j = 2
    while i - j >= 2:
        result += (cache[i-j] * symmetry[j]) % P
        j += 2

    cache[i] = result % P
    symmetry[i] = cache[i-2]


t = int(input())

for _ in range(t):
    n = int(input())
    print(f"{cache[n]}")
