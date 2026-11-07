f=lambda x,y:(y-~x*2)//5
a,b,c,d=map(int,open(0).read().split())
print(abs(f(a,-b)-f(c,-d))+abs(f(b,a)-f(d,c)))