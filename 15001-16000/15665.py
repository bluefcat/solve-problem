from itertools import permutations 

n, m = map(int, input().split())
arr = [*map(int, input().split())]*n
for x in sorted([*set(x for x in permutations(arr, r=m))]):
    print(*x)
