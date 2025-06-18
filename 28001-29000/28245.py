import sys 
input=sys.stdin.readline


for _ in "*"*int(input()):
    m=int(input())
    x=[i for i,r in enumerate(bin(m)[2:][::-1]) if r == '1'][-2:]
    if len(x) == 1:
        if m == 2:
            print(0, 0)
        else:
            print(0, x[-1])
        continue
    print(*x)

