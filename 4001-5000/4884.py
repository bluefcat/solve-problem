import sys, math
input = sys.stdin.readline 

while True:
    g, t, a, d = map(int, input().split())
    if g == t == a == d == -1:
        break

    x, y, k = g*(t*(t-1)//2), g*a+d, 0
    l = math.log2(g*a+d)
    k = 2**(int(l) + (not l.is_integer())) - y
    
    p = y+k
    while p != 1:
        p >>= 1 
        x += p

    print(f"{g}*{a}/{t}+{d}={x}+{k}")
        
