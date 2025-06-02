import sys
MOD = 998_244_353

def fact(x):
    result = 1 
    for i in range(1, x+1):
        result = (result * i) % MOD
    return result

sys.setrecursionlimit(3000)

input = sys.stdin.readline 

def processing(query, cur, arr):
    result = 1
    if len(query) == cur:
        return result
    
    oper, idx = query[cur]
    tmp = {}
    for x in arr:
        tmp[x[idx-1]] = tmp.get(x[idx-1], []) + [x]

    narr = []
    for v in tmp.values():
        if len(v) > 1:
            narr.extend(v)
    
    match oper:
        case 1:
            result = (result * fact(len(narr))) % MOD
        case 2:
            result = (result * processing(query, cur+1, narr)) % MOD
    return result

n, q = map(int, input().split())
#arr = [[1 for _ in range(2000)] for _ in range(2000)]
#tmp = [[1, 1]] +  [[2, 1] for _ in range(1999)]
arr = [[*map(int, input().split())] for _ in range(n)]
tmp = [[*map(int, input().split())] for _ in range(q)]
query = []
for oper, idx in reversed(tmp):
    if oper == 1:
        query.append((oper, idx))
        break
    query.append((oper, idx))

print(processing(query, 0, arr))

