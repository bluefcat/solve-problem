R = 1000000007
def product(x, y):
    return [
        [sum(
            a * b for a, b in zip(r1, r2)
        ) % R for r2 in zip(*y)]
        for r1 in x
    ]

def pow(x, n):
    b = [[int(i == j) for i, _ in enumerate(r)] for j, r in enumerate(x)]
    while n:
        if n & 1:
            b = product(x, b)
        n >>= 1
        x = product(x, x)
    
    return b

import sys
input = sys.stdin.readline

t, n, d = map(int, input().split())
q = [[0 for _ in range(n)] for _ in range(n)]

a = int(input())

for _ in range(a):
    x, y, d = map(int, input().split())
    x, y = x-1, y-1
    q[x][y] = d

r = pow(q, d)

for l in r:
    print(l)