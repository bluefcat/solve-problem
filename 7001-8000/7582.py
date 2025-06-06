import sys 
input = sys.stdin.readline 

def filter(iter, func):
    for i in iter:
        yield func(i)

x = [*open(0)]

while x:
    n,c = x[0].split();c=int(c)
    cur,s = map(int, x[1:3]) 
    for l, b in filter(x[3:3+s], func=lambda x: map(int, x.split())):
        cur = max(0, cur-l)
        cur = min(c, cur+b)

    print(n, cur)
    x = x[s+4:]
