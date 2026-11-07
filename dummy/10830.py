def product(x, y):
    return [
        [sum(
            a * b for a, b in zip(r1, r2)
        ) % 1000 for r2 in zip(*y)]
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

p, n = map(int, input().split())

x = []
for _ in range(p):
    x.append(list(map(int, input().split())))

r = pow(x, n)
for l in r:
    print(' '.join(map(str, l)))
