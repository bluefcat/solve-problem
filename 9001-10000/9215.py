import sys 
from fractions import Fraction

input = sys.stdin.readline
cnt = 0
while n := int(input()):
    cnt += 1
    if n == 0:
        break
    
    result = Fraction(0)
    for _ in range(n):
        x = [*map(Fraction, input().split(','))]
        result += sum(x)

    d, n = result.denominator, result.numerator
    if d >= n:
        print(f"Test {cnt}: {result}")
    elif d < n:
        print(f"Test {cnt}: {n//d},{Fraction(n%d, d)}")
