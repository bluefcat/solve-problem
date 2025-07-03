from itertools import permutations
def d(a, b):
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**(0.5)
pos = [[*map(int, input().split())] for _ in range(4)]
result = 10**9

for n in permutations([1,2,3], r=3):
    cur = pos[0]
    tmp = 0
    for x in n:
        tmp += d(cur, pos[x])
        cur = pos[x]
    result = min(tmp, result)
print(int(result))

