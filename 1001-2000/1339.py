from collections import Counter
n = sorted(
    [input().strip()[::-1] for _ in range(int(input()))],
    key= lambda x: len(x)
)

mask = {chr(k): -1 for k in range(ord('A'), ord('A')+10)}
c = []
for i, _ in enumerate(max(n, key=lambda x: len(x))):
    tmp = Counter([s[i] for s in n if len(s) > i])
    c.append(tmp)

cand = 9

for cnt in reversed(c):
    while True:
        t = max(cnt, key=lambda x: cnt[x])
        if cnt[t] == 0:
            break
        if mask[t] != -1:
            cnt[t]=0;
            continue
        mask[t] = cand 
        cand -= 1
        cnt[t]=0

print(sum(sum(mask[w] * (10**i) for i, w in enumerate(x)) for x in n))

