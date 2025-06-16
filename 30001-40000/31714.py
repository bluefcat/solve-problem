import sys
input = sys.stdin.readline 

n,m,d=map(int, input().split())
prev = [0 for _ in range(n)]
flag = True
for i in range(n):
    cur = sorted(map(lambda x: int(x)+d*i, input().split()))
    flag &= not any(x >= y for x, y in zip(prev, cur))
    prev = cur
        
if flag:
    print("YES")
    exit(0)
print("NO")

