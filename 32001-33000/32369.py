n, a, b = map(int, input().split())
if a+1 == b:
    print(b+a*(n-1)+1, b+a*(n-1))
else:
    p = (a+b)*(n//2)+b*(n%2)
    if n & 1:
        print(p, p-(b-a-1))
    else:
        print(p+1, p)
