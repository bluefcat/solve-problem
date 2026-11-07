import sys
input = sys.stdin.read
n, *l = map(int, input().split())
l.sort()
c = int(round((n * 15) / 100))

k = l[c:-c]
if len(k) == 0:
    print(0)
else:
    print(int(round(sum(k)/len(k))))