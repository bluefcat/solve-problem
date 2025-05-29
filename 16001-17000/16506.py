def f(o,p,q,r):
    c='C'in o
    s="ADDSUBMOVANDORRNOTMUTLSLLSRASRRLLRRR"
    o=s.find(o[:2]+o[-(1+c)])/3
    o,p,q,r=map(lambda x:f"{bin(int(x))[2:]:0>3}",[o,p,q,r])
    r=f"{r:0>{3+c}}"
    print(f"{o:0>4}{+c}0{p}{q}{r:0<4}")
[f(*x.split())for x in[*open(0)][1:]]
