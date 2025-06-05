from itertools import product
h=[input()for _ in range(int(input()))]
for i in h:
    d={''.join(k):0 for k in product("TH",repeat=3)}
    for e in d:
        d[e]=len(set(i.find(e,c) for c,_ in enumerate(i) if i.find(e,c)!=-1))
    print(' '.join(map(str,d.values())))
