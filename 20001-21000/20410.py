h=100
m,s,p,q=map(int,input().split())
for a,c in [(i//h,i%h)for i in range(h*h)]:
    i=(a*s+c)%m
    j=(a*i+c)%m
    if i==p and j==q:
        print(a,c)
        exit(0)
