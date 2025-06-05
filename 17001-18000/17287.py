n=input().strip()
r,c,m=0,0,"..(){}[]"

for w in n:
    x=m.find(w)
    if x==-1:
        r=max(r,c) 
    else:
        c+=(-1)**(x&1)*(x//2)
print(r)
