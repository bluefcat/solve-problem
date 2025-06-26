ans=[]
n,q,k=map(int,input().split())
a=[*map(int,input().split())]

def d(a,p,r):
    global k,ans
    x=a[r] 
    i=p-1 
    for j in range(p,r):
        if a[j] <= x:
            i+=1 
            a[i], a[j]= a[j], a[i]
            k-=1
            if k == 0:
                ans = [x for x in a]
    if i+1 != r:
        a[i+1], a[r]= a[r], a[i+1]
        k-=1
        if k == 0:
            ans = [x for x in a]
    return i+1

def s(a,p,r,q):
    if p == r: return a[p]
    t=d(a,p,r)
    k=t-p+1 
    if q<k: return s(a,p,t-1,q)
    elif q==k: return a[t]
    return s(a,t+1,r,q-k)

s(a,0,n-1,q)
if k > 0:
    print(-1)
    exit(0)
print(*ans)

