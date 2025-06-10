def f(x):
    r=0
    while True:
        for i in range(9,1,-1):
            if x % i == 0:
                x //= i
                r += 1
                break
        else:
            break
    if x>=10:
        return -1
    return r

[print(f(int(input()))) for _ in range(int(input()))]
