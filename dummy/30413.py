def f(x, e, m):
    result = 1 
    while(e):
        if e & 1:
            result = (result * x) % m
        x = (x*x) % m
        e >>= 1
    return result 

a, b = map(int, input().split())
m = 1_000_000_007
if a == 1:
    print(b%m)
else:
    print(((f(a, b, m)-1) * f(a-1, m-2, m))%m)