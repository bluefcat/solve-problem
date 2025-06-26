_,e=map(int, input().split())
a=sorted([*map(int, input().split())])
d,r=a[0],1
for i in a:
    if d+e <= i:
        r+=1
    d=i 
print(r)
