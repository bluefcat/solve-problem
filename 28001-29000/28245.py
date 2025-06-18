import sys 
input=sys.stdin.readline

def f(x):
    a, b =0, 0
    t=[]
    r = 999999999
    for i in range(0, 20):
        for j in range(i, 20):
            k = 2**i+2**j
            if r >= abs(x - k):
                if r > abs(x-k):
                    t = []
                r = abs(x - k)
                a,b=i,j
                t.append((k, a, b))
    print(t)
    return a,b


for _ in "*"*int(input()):
    m=int(input())
    x=[i for i,r in enumerate(bin(m)[2:][::-1]) if r == '1'][-2:]
    if len(x) == 1:
        if m <= 2:
            print(0, 0)
        else:
            print(x[-1]-1, x[-1]-1)
        continue

    a=2**(x[1]+1)
    b=2**(x[0]+1)
    k=2**x[0]+2**x[1]
    t = sorted([
            (abs(m-k), k, (x[0], x[1])),
            (abs(m-a), a, (x[1], x[1])),
            (abs(m-b), b, (x[0], x[0]))
            ], 
           key= lambda x: (x[0], x[1])
    )[0][2]



    print(*t)

