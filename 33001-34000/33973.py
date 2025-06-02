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
    for i, x in enumerate(arr):
        tmp[x[0][idx-1]] = tmp.get(x[0][idx-1], []) + [i]

    narr = 0
    for v in tmp.values():
        if len(v) == 1:
            arr[v[0]][1] = True
        if len(v) > 1:
            for i in v:
                narr += (not arr[i][1])
    
    arr = sorted(arr, key=lambda x: x[0][idx-1])

    match oper:
        case 1:
            return fact(narr) % MOD
        case 2:
            return  processing(query, cur+1, arr) % MOD
    return result

n, q = map(int, input().split())
arr = [[*map(int, input().split())] for _ in range(n)]
arr = [[x, False] for x in arr]
tmp = [[*map(int, input().split())] for _ in range(q)]
query = []
for oper, idx in reversed(tmp):
    if oper == 1:
        query.append((oper, idx))
        break
    query.append((oper, idx))

print(processing(query, 0, arr))

