import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    l = [*map(int, input().split())]
    s = sum(l)
    
    if (s/n).is_integer():
        x = (s//n)

        for i in range(1, n-1):
            delta = l[i-1] - x
            l[i-1] = x
            l[i+1] += delta

        if any(x != ll for ll in l):
            print("NO")

        else:

            print("YES")
    else:
        print("NO")
    ...
