input()
x=[*map(int,input().split())][::-1]
t,s=1,[]
while x:
    if x[-1] == t:
        x.pop()
        t+=1
    elif s and s[-1] == t:
        s.pop()
        t+=1
    else:
        s+=[x[-1]]
        x.pop()

if s:
    print("Sad")
    exit(0)
print("Nice")
