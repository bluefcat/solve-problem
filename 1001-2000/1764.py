n, m = map(int, input().split())
no_hear = set([input() for _ in range(n)])
no_look = set([input() for _ in range(m)])
result = no_hear & no_look
print(len(result))
[print(name) for name in sorted(list(result))]
