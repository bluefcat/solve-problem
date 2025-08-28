def product(x, y):
    return [
        [sum(
            a * b for a, b in zip(r1, r2)
        ) % 1_000_000_007 for r2 in zip(*y)]
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

x = [[1, 1], [1, 0]]
n = int(input())


r = pow(x, n)
print((r[0][0] * r[0][1]) % 1_000_000_007)
