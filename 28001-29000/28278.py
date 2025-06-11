f={
    1:lambda k,v: k.append(v),
    2:lambda k:print(k and k.pop()or -1),
    3:lambda k:print(len(k)),
    4:lambda k:print(+(not k)),
    5:lambda k:print(k and k[0]or -1),
}
s=[]
for x in [*open(0)][1:]:
    k,*v=map(int,x.split())
    f[k](s,*v)
