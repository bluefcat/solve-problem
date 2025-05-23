import sys 
input = sys.stdin.readline 

l = []
opers = {
    "order": lambda l, n, t: l.append((n, t)),
    "sort": lambda l: l.sort(key=lambda x: (x[1], x[0])),
    "complete": lambda l, n: l.remove(l[([x[0] for x in l].index(n))]),
}

n, m = map(int, input().split())
for _ in range(n):
    oper, *x = input().split()
    x = map(int, x)
    opers[oper](l, *x)

    if not l:
        print("sleep")
        continue
    print(*[x[0] for x in l])
