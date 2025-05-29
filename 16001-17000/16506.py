import sys 
input = sys.stdin.readline 

def f(oper,p,q='0',r='0'):
    p,q,r=map(lambda x:bin(int(x))[2:], [p,q,r])
    opers=["ADD","SUB","MOV","AND","OR","NOT","MULT","LSFTL","LSFTR","ASFTR","RL","RR"]
    c = 'C'in oper; 
    if c: 
        oper=oper[:-1]
        r=f"{r:0>4}"
    else:
        r=f"{r:0>3}"
    print(f"{bin(opers.index(oper))[2:]:0>4}{+c}0{p:0>3}{q:0>3}{r:0<4}")


_ = [f(*x.split()) for x in [*map(str,open(0))][1:]]
