_,m=map(int,input().split())
a=[x for x in map(int,input().split())]
r=0
while m > 0 and a:
    a=[x for x in a if x >= 10]
    r+=sum(10==x for x in a)
    a=[x for x in a if x > 10]

    tmp=[x for x in a if x==20]
    r += 2*min(len(tmp),m)
    m -= min(len(tmp),m)
    a=[x for x in a if x != 20]
    
    if a:
        a[0] = a[0]-10
        m-=1 
        r+=1


print(r)


