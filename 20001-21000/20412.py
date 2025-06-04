m,s,x1,x2=map(int,input().split())
rs,rx1=pow(s,-1,m),pow(x1,-1,m)
p1,p2=(x1*rs)%m,(x2*rx1)%m
if s==x1:
    print(1,0)
    exit(0)
a=((x2-x1)*pow(x1-s,-1,m))%m
c=((p2-p1)*pow(rx1-rs,-1,m))%m
print(a,c)
