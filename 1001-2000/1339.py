from collections import Counter
n = sorted(
    [input().strip()[::-1] for _ in range(int(input()))],
    key= lambda x: len(x)
)

m = {k: -1 for k in range(ord('A'), ord('A')+27)}
c = {k: 0 for k in range(ord('A'), ord('A')+27)}
a = {k: 0 for k in range(ord('A'), ord('A')+27)}

for x in n:
    for i, w in enumerate(x):
        c[ord(w)] = 1
        a[ord(w)] += (10**i)

cand = 9
while True:
    w = max(m.keys(), key=lambda x: a[x]*c[x])
    if c[w] == 0:
        break
    m[w], c[w] = cand, 0
    cand -= 1

print(sum(sum(m[ord(w)] * (10**i) for i, w in enumerate(x)) for x in n))

