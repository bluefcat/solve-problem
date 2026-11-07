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

q = [
    [0, 1, 0, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 0, 0, 1],
    [0, 1, 0, 1, 0, 0, 1, 1],
    [0, 0, 1, 0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0, 1, 0, 0],
    [0, 0, 0, 0, 1, 0, 1, 0],
    [0, 0, 1, 1, 0, 1, 0, 1],
    [1, 1, 1, 0, 0, 0, 1, 0]
    ]
d = int(input())
r = pow(q, d)

print(r[0][0])