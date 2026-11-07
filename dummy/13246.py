def add(x, y):
    return [
        [(x + y) % 1000 for x, y in zip(rx, ry)] for rx, ry in zip(x, y)
    ]

def product(x, y):
    return [
        [sum(
            a * b for a, b in zip(r1, r2)
        ) % 1000 for r2 in zip(*y)]
        for r1 in x
    ]

def powi(x, n):
    r = [[int(i == j) for i, _ in enumerate(r)] for j, r in enumerate(x)]
    m = [[-int(i == j) for i, _ in enumerate(r)] for j, r in enumerate(x)]
    b = [[int(i == j) for i, _ in enumerate(r)] for j, r in enumerate(x)]
    while n:
        if n & 1:
            b = product(add(x, r), b)
        n >>= 1
        x = product(x, x)
    
    return add(b, m)

def pow(x, n):
    b = [[int(i == j) for i, _ in enumerate(r)] for j, r in enumerate(x)]
    while n:
        if n & 1:
            b = product(x, b)
        n >>= 1
        x = product(x, x)
    
    return b

import sys
import math
input = sys.stdin.readline

p, n = map(int, input().split())

x = []
for _ in range(p):
    x.append(list(map(int, input().split())))

# n이 2^n-1 꼴일때만 정상적으로 작동함

k = int(math.floor(math.log2(n)))
diff = n - (2 ** k - 1)

r = powi(x, 2 ** k - 1)

b = 0
while diff > 0:
    print(2 ** k - 1, diff)
    print()
    
    b += 2 ** k

    k = int(math.floor(math.log2(diff)))
    diff = diff - 2 ** k - 1

    r = add(r, product(powi(x, 2 ** k - 1), pow(x, b)))




for i in range(2 ** k, n+1):
    r = add(r, pow(x, i))

for l in r:
    print(' '.join(map(str, l)))
