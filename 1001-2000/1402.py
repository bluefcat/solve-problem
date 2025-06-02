import sys 
input = sys.stdin.readline

def factorize(x):
    result = []
    for i in range(2, int(x**0.5)+1):
        while x % i == 0:
            result.append(i)
            x //= i
    if x != 1:
        result.append(x)
    return result

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    if a <= b:
        print("yes")

    elif sum(factorize(a)) <= b:
        print("yes")
    
    else:
        print("no")
    
