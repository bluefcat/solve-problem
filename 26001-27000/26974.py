import sys
input = sys.stdin.readline 

def f(r, i, j):
    if i == j:
        return 0
    return max(r[i:j+1]) - min(r[i:j+1])

n = int(input())

field = [*map(int, input().split())]
result = [0]
tmp = field
conds = [tmp]

for idx in range(n-1):
    diff = tmp[1]
    p, q = result[idx] + diff, result[idx] - diff
    
    if all(
        f(result+ [p], i, idx+1) == cond[idx+1]
        for i, cond in enumerate(conds)
    ):
        result.append(p)
    else:
        result.append(q)

    tmp = [*map(int, input().split())]
    conds.append([0] * (idx+1) + tmp)
    


x = min(result)
if x < 0:
    result = [*map(lambda k: k+abs(x), result)]
print(*result)




