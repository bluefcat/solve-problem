def check(n):
    return (n&(n-1)) == 0

x, y, z = map(int, input().split())
m, r = (x+y+z)//3, (x+y+z)%3
if r == 0:
    mx, my, mz = abs(m-x), abs(m-y), abs(m-z)
    x, mx = max(x, mx), min(x, mx)
    y, my = max(y, my), min(y, my)
    z, mz = max(z, mz), min(z, mz)
    if (x%mx == 0 and check(x//mx)) or (y%my == 0 and check(y//my)) or (z%mz == 0 and check(z//mz)):
        print(1)
    else:
        print(0)
else:
    print(0)