_,m=map(int,input().split())
a=[x for x in map(int,input().split())]
r=0
while True:
    a=[x for x in a if x >= 10]
    r+=sum(10==x for x in a)
    a=[x for x in a if x > 10]

    tmp=[x for x in a if x==20]
    r += 2*min(len(tmp),m)
    m -= min(len(tmp),m)
    a=[x for x in a if x != 20]
    
    if (m == 0) or not a:
        break

    if a:
        i = a.index(min(a, key=lambda x: (x%10,x)))
        a[i] = a[i]-10
        m-=1 
        r+=1

print(r)

