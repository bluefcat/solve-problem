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


#n, m = map(int, input().split())

#q = [[0 for j, _ in enumerate(range(n))] for i, _ in enumerate(range(n))]

#for _ in range(m):
#    x, y = map(int, input().split())
#    x, y = x-1, y-1
#    q[x][y] = 1
#    q[y][x] = 1
d = int(input())
     #1  2  3  4  
q = [[0, 0, 0, 1], #1
     [0, 0, 1, 0], #2
     [0, 0, 0, 0], #3
     [0, 0, 0, 0], #4
     ]

r = pow(q, d)

for l in r:
    print(l)

print(r[0][0])