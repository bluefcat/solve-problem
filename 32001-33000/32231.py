from sys import stdin
import math
from decimal import * 

getcontext().prec = 32

input = stdin.readline

def get_c2(x1, y1, x2, y2):
    return Decimal(((y2*y2+x2*x2)-(y1*y1+x1*x1))/(Decimal(2)*(x2-x1)))

def get_c1(c2, x1, y1):
    return Decimal(1)/(((x1-c2)*(x1-c2) + y1**Decimal(2)).sqrt())

def atanh(x):
    return -(Decimal((1+x)/(1-x))).ln()/Decimal(2)

t = int(input())

for _ in range(t):
    x1, y1, x2, y2 = map(Decimal, input().split())
    if x1 == x2:
        print(abs(math.log(y2/y1)))
        continue 

    if x1 > x2:
        x1, x2 = x2, x1 
        y1, y2 = y2, y1

    c2 = get_c2(x1, y1, x2, y2)
    c1 = get_c1(c2, x1, y1)
    
    f = lambda c, y: Decimal(1)-(c*y)**Decimal(2)
    inte = lambda k: Decimal(1)/k.sqrt()*(k.sqrt())*atanh(k.sqrt())
    
    if c2 < x2 and x1 <= c2:
        print(2*atanh(0) - (inte(f(c1, y2)) + inte(f(c1, y1))))
    else:
        if y1 > y2:
            y1, y2 = y2, y1
        print(inte(f(c1, y2)) - inte(f(c1, y1)))





    
