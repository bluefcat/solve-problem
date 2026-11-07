import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    b, d = input().split()
    b = int(b)
    t = 1
    r = 0
    for x in d[::-1]:
        a = int(x)
        r = (r + (a * t) % (b-1)) % (b-1)
        t = (t*b) % (b-1)

    print(r)