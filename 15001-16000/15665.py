from itertools import product

n, m = map(int, input().split())
arr = [*map(int, input().split())]
for x in sorted([*set(x for x in product(arr, repeat=m))]):
    print(*x)
