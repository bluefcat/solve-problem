a = sorted(map(int, input().split()))
d = [a[1]-a[0], a[2]-a[1]]
if d[0] == d[1]:
    print(a[2]+d[0])
elif d[0] == d[1]*2:
    print(a[0]+d[1])
else:
    print(a[1]+d[0])
