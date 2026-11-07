import sys
from fractions import Fraction

def parsing(f: str):
    result = [0, 0, 0]
    target = f.split()
    for i, e in enumerate(target):
        if e[-1] in ['x', 'y']:
            try:
                target[i] = f"{int(e[:-1])}*{e[-1]}"
            except:
                if e[0] != e[-1]:
                    target[i] = f"{e[0]}{e[-1]}"
                else:
                    target[i] = f"{e[-1]}"

    target = ''.join(target)

    result[2] = eval(target, {}, {'x': 0, 'y': 0})
    result[0] = eval(target, {}, {'x': 1, 'y': 0}) - result[2]
    result[1] = eval(target, {}, {'x': 0, 'y': 1}) - result[2]
    return result

def calc(left, right):
    left[0] -= right[0]; right[0] = 0
    left[1] -= right[1]; right[1] = 0
    right[2] -= left[2]; left[2] = 0
    return [left[0], left[1], right[2]]

def product(x, y):
    return [
        [sum(i*j for i, j in zip(row, col)) for col in zip(*y)] for row in x
    ]

def printf(fraction: Fraction):
    if fraction.denominator == 1:
        print(fraction.numerator)
        return
    
    print(f"{fraction.numerator}/{fraction.denominator}")

_ = input()
data = [x.strip() for x in sys.stdin.readlines() if x.strip()]

for i, _ in enumerate(data[::2]):
    f0, f1 = data[2*i], data[2*i+1]

    l0, r0 = f0.split("=")
    l1, r1 = f1.split("=")
    l0, r0 = parsing(l0), parsing(r0)
    l1, r1 = parsing(l1), parsing(r1)

    f0 = calc(l0, r0)
    f1 = calc(l1, r1)

    det = f0[0] * f1[1] - f0[1] * f1[0]
    


    f = Fraction

    if det == 0:
        x, y= None, None
        if all(c == 0 for c in f0):
            tx, ty = 0, 0
            if f1[0] != 0:
                tx = f(f1[2], f1[0])
            if f1[1] != 0:
                ty = f(f1[2], f1[1])
            if tx * f1[0] + ty * f1[1] == f1[2]:
                if f1[0] != 0:
                    x = tx
                if f1[1] != 0:
                    y = ty

        if all(c == 0 for c in f1):
            tx, ty = 0, 0
            if f0[0] != 0:
                tx = f(f0[2], f0[0])
            if f0[1] != 0:
                ty = f(f0[2], f0[1])

            if tx * f0[0] + ty * f0[1] == f0[2]:
                if f0[0] != 0:
                    x = tx
                if f0[1] != 0:
                    y = ty

        if f0[0] != 0:
            f0 = [f(e, f0[0]) for e in f0]
        if f0[1] != 0:
            f0 = [f(e, f0[1]) for e in f0]
        if f1[0] != 0:
            f1 = [f(e, f1[0]) for e in f1]
        if f1[1] != 0:
            f1 = [f(e, f1[1]) for e in f1]

        if all(c0 == c1 for c0, c1 in zip(f0, f1)) and \
            ((f0[0] == 0 and f0[1] != 0) or (f1[0] == 0 and f0[1] != 0) or \
             (f0[0] != 0 and f0[1] == 0) or (f1[0] != 0 and f0[1] == 0)
             )  :
            tx, ty = 0, 0
            if f1[0] != 0:
                tx = f(f1[2], f1[0])
            if f1[1] != 0:
                ty = f(f1[2], f1[1])
            
            if tx * f0[0] + ty * f0[1] == f0[2]:
                if f0[0] != 0:
                    x = tx
                if f0[1] != 0:
                    y = ty

        if x == None:
            print("don't know")
        else:
            printf(x)
        
        if y == None:
            print("don't know")
        else:
            printf(y)
        print()
        continue
    
    matr = [
        [f(f1[1], det), f(-f0[1], det)], 
        [f(-f1[0], det), f(f0[0], det)]
    ]
    r = [[f(f0[2], 1)], [f(f1[2], 1)]]
    result = product(matr, r)

    printf(result[0][0])
    printf(result[1][0])
    print()
    
