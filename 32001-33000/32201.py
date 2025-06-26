_=input()
x=[*map(int,input().split())]
y=[*map(int,input().split())]
d={k:v for v,k in enumerate(y)}
for v,k in enumerate(x):
    d[k] = v-d[k]

p = max(d, key=lambda x: d[x])
r = [x for x in d if d[x] == d[p]]
print(*r)
