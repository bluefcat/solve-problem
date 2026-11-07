x, y = map(int, input().split())
if x not in [0, 2, 5]:
    x = -1
if y not in [0, 2, 5]:
    y = -1

if x == y:
    print("=")
else:
    if x == 0:
        if y != 5:
            print(">")
        else:
            print("<")
    elif x == 2:
        if y != 0:
            print(">")
        else:
            print("<")
    elif x == 5:
        if y != 2:
            print(">")
        else:
            print("<")
    else:
        print("<")