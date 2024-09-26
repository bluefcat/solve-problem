import sys

input = sys.stdin.readline

T = int(input().strip())

for _ in range(T):
    n = int(input().strip())
    closet = {}
    for _ in range(n):
        v, k = input().strip().split()
        closet[k] = closet.get(k, set()) | set([v])
   
    result = 1
    for w in closet.values():
        result *= (len(w)+1)

    print(result-1)
