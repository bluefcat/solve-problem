"""main"""

def f(x):
    """
    f
    """
    x -= 1
    result = [5, 13]

    for i in range(2, x):
        result[i % 2] = result[i % 2] + result[(i + 1) % 2] + 1

    return result[x % 2]

def g(idx):
    """
    g
    """
    n = 45
    x = [f(n-1), f(n-2)]

    while n > 2:
        if idx <= x[0]:
            n -= 1
            x = [f(n-1), f(n-2)]

        elif idx == x[0] + 1:
            return "Messi Messi Gimossi"

        else:
            n -= 2
            if n > 2:
                idx -= x[0] + 1
            x = [f(n-1), f(n-2)]

    return "Messi Gimossi"[idx-1]

x = int(input())
print(g(x))