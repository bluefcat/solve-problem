import sys;input=sys.stdin.readline
from fractions import Fraction
from itertools import combinations

def get_score(ans, target):
    return Fraction(
        sum(x == y for x, y in zip(ans, target)),
        len(ans)
    )

def get_single(ans, cand):
    return max(get_score(ans, x) for x in cand)

def get_ensemble(ans, target):
    tmp = [0 for _ in ans]
    for i, t in enumerate(zip(*target)):
        if t.count(0) > t.count(1):
            tmp[i] = 0 
        else:
            tmp[i] = 1
    return get_score(ans, tmp)

def find(ans, cand):
    result = 0
    for ch in range(3, len(ans)+1, 2):
        for i in combinations(cand, ch):
            result = max(result, get_ensemble(ans, i))
    return result

n, _ = map(int, input().split())
ans = [*map(int, input().split())]
cand = [[*map(int, input().split())] for _ in range(n)]


print(+(get_single(ans, cand) < find(ans, cand)))
