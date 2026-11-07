import sys

input = sys.stdin.readline

def oper(x, i):
    if(x[i] == "0"):
         return x
    return x[:i-1] + f"{int(x[i]) - 1}" + x[i-1:i] + x[i+1:]

t = int(input())

for _ in range(t):
    x  = input().strip()

    if(len(x) == 1):
        print(x)
        continue
    
    y = x
    t = 1
    for i in range(1, len(x)):
        if int(y[i-1]) < int(y[i]) - 1:
            t = i

    oper(y, t)

    result = y
    for _ in range(10*len(y)+1):
        t = 0
        for i in range(1, len(y)):
            if int(y[i-1]) < int(y[i]) - 1:
                t = i

        if t == 0:
            break

        y = oper(y, t)

        if result < y:
            result = y

    print(result)