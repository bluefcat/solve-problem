def prod(x, *q):
    if not q:
        return x
    y = prod(*q)
    if len(x[0]) != len(y):
        raise Exception()
    return [[sum(x*y for x, y in zip(r, c)) for c in zip(*y)] for r in x]

n = int(input())
m = []
for _ in range(n):
    r,_ = map(int, input().split())
    m.append([[*map(int,input().split())] for _ in range(r)])

try:
    print(sum(sum(x for x in r) for r in prod(*m)))
except:
    print(-1)
