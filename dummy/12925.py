R = 1000
from decimal import *
getcontext().prec = 28

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

t = int(input())

import math

for i in range(1, t+1):
    n = int(input())
    a = Decimal(3) + Decimal(5) ** Decimal(0.5)
    q = [[a, 0], [0, a]]
    r = pow(q, n)
    print(f"Case #{i}: {math.floor(r[0][0]):03.0f}")
    t -= 1
