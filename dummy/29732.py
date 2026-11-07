import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

a = input().strip()

for x in a:
    assert (x == '.') or (x == 'R')

l = [1 if x == 'R' else 0 for x in a]
r = [0 for _ in l]

print(l, r)

for i, e in enumerate(l):
    if e == 1:
        for j in range(max(0, i-k), min(i+k, n-1)+1):
            r[j] = 1
print(l, r)
print("YES" if sum(r) <= m else "NO")