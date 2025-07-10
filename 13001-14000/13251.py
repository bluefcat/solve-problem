_=input()
a=[*map(int,input().split())]
c=int(input())-1
r=0
for x in a:
    t=1
    for i in range(0,c):
        t *= (x-(i+1))/(sum(a)-(i+1))
    r+=x/(sum(a))*t
print(r)
