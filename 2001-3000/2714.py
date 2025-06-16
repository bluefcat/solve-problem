import sys 
input=sys.stdin.readline
for _ in "*"*int(input()):
    r,c,s=input().split()
    c=int(c)
    f=[[*s[c*i:c*i+c]]for i,_ in enumerate(s[::c])]
    r='' 
    while f:
        r+=''.join(f.pop(0))
        f = [*zip(*f)][::-1]
    m=''
    for i,_ in enumerate(r[::5]):
        x=int(f"{r[5*i:5*i+5]}",2)
        if x == 0:
            m += ' '
        else:
            m += chr(ord('A')-1+x)
    print(m.strip())

