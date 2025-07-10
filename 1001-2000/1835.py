n=int(input())
a=[]

for i in range(n,0,-1):
    a = [i] + a
    l=len(a)
    p = l-(i%l)
    a = a[p:] + a[0:p]
print(*a)
