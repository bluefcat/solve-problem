import sys
from collections import Counter
input = sys.stdin.readline

def get_x(m) -> int:
    result = [0, 0]
    t = [*zip(*m)]

    for row in m:
        result[0] += sum(x > y for x, y in zip(row, row[1:]))

    for row in t:
        result[1] += sum(x > y for x, y in zip(row, row[1:]))

    return result

t = int(input())

for _ in range(t):
    r, c = map(int, input().split())
    n = set()
    
    matrix = [[*map(int, input().split())] for _ in range(r)]
    target = [[*map(int, input().split())] for _ in range(r)]
    
    mc = Counter([e for row in matrix for e in row])
    tc = Counter([e for row in target for e in row])

    if len(mc) != len(tc):
        print("NIE")
    
    for k in tc:
        if mc.get(k, -1) != tc[k]:
            print("NIE")
            break
    else:
        mr, mc = get_x(matrix)
        tr, tc = get_x(matrix)
        
        if not(mr % r == tr % r and mc % c == tc % c):
            print("NIE")
        else:
            print("TAK")
