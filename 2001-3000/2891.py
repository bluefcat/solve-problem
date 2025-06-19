n=int(input().split()[0])
a=[*map(int,input().split())]
b=[*map(int,input().split())]
p={x:1 for x in range(1,n+1)}
for x in a:
    p[x] -= 1 
for x in b:
    p[x] += 1
t={k:v for k,v in p.items()}
r=101
for k in t:
    if t[k] != 2:
        continue
    if k-1 > 0 and t[k-1] == 0 and t[k] == 2:
        t[k] -= 1 
        t[k-1] += 1
    
    if k+1 <= len(t) and t[k+1] == 0 and t[k] == 2:
        t[k] -= 1 
        t[k+1] += 1

r = min(r, len([v for v in t.values() if v == 0]))

t={k:v for k,v in p.items()}
for k in t:
    if t[k] != 2:
        continue
    if k+1 <= len(t) and t[k+1] == 0 and t[k] == 2:
        t[k] -= 1 
        t[k+1] += 1
    if k-1 > 0 and t[k-1] == 0 and t[k] == 2:
        t[k] -= 1 
        t[k-1] += 1
    
r = min(r, len([v for v in t.values() if v == 0]))
print(r)


