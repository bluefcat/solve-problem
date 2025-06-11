a,b,c,x,y=map(int,input().split())
if a+b<2*c:
    print(x*a+y*b)
    exit(0)
print(min(min(x,y)*c*2+(max(x,y)-min(x,y))*-max([(x,-a),(y,-b)])[1],max(x,y)*c*2))

