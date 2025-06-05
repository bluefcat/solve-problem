from collections import Counter
n = sorted(
    [input().strip()[::-1] for _ in range(int(input()))],
    key= lambda x: len(x)
)

mask = {chr(k): -1 for k in range(ord('A'), ord('A')+10)}
app = {chr(k): 0 for k in range(ord('A'), ord('A')+10)}
for x in n:
    for w in x:
        app[w] += 1


c = []
for i, _ in enumerate(max(n, key=lambda x: len(x))):
    tmp = Counter([s[i] for s in n if len(s) > i])
    c.append(tmp)

cand = 9

for cnt in reversed(c):
    while True:
        p, pc = [], 0
        for k, v in cnt.items():
            if pc < v:
                p, pc = [k], v
            elif pc == v:
                p.append(k)
        
        t = max(p, key=lambda x:app[x])

        if cnt[t] == 0:
            break
        if mask[t] != -1:
            cnt[t]=0;
            continue
        mask[t] = cand 
        cand -= 1
        cnt[t]=0

print(sum(sum(mask[w] * (10**i) for i, w in enumerate(x)) for x in n))

