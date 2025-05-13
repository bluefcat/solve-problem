import math
h = int(input())

q = math.log(h, 2)
if not q.is_integer():
    print("-1")
    exit(0)

q = math.log(q, 2)
if not q.is_integer():
    print("-1")
    exit(0)

q = int(q)
print(q+1, q+1)
print(*[1 for _ in range(q)])
print(*[1 for _ in range(q-1)] + [2])

