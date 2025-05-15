import sys
input = sys.stdin.readline

def get_x(m) -> int:
    result = [[], []]

    for row in m:
        result[0].append(hash(tuple(sorted(row))))

    for row in [*zip(*m)]:
        result[1].append(hash(tuple(sorted(row))))
    return result

t = int(input())

for _ in range(t):
    r, c = map(int, input().split())
    
    matrix = [[*map(int, input().split())] for _ in range(r)]
    mr = get_x(matrix)

    matrix = [[*map(int, input().split())] for _ in range(r)]
    tr = get_x(matrix)
    flag = True
    for m, t in zip(mr, tr):
        check = {e: False for e in m}
        for tmp in t:
            if check.get(tmp, None) != None:
                check[tmp] = True 
        flag &= all(i for i in check.values())
   
    if flag:
        print("TAK")
    else:
        print("NIE")

