import sys 
input=sys.stdin.readline

def f(x):
    a, b =0, 0
    t=[]
    r = 999999999
    for i in range(0, 100):
        for j in range(i, 100):
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
    if m == 1:
        print(0, 0)
        continue
    b, b1 = 1,0
    while b < m:
        b *= 2
        b1 += 1

    x=[i for i,r in enumerate(bin(m)[2:][::-1]) if r == '1'][-2:]
    x1 = 2**x[0] + 2**x[-1]    

    if abs(x1-m) <= abs(b-m):
        print(x[0], x[1])
        continue 
    print(b1-1, b1-1)





