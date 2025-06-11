input()
x=[*map(int,input().split())][::-1]
t,s=1,[]
while x:
    if x[-1] != t:
        s+=[x[-1]]
    else:
        t+=1
    x.pop()
while s:
    if s[-1] != t:
        print("Sad")
        exit(0)
    t+=1
    s.pop()
print("Nice")
