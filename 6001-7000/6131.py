import sys
input = sys.stdin.readline

n = int(input())

result, a = 0, 1
while 500**2 >= (a**2)+n:
    result += (((a**2)+n)**0.5).is_integer()
    a += 1

print(result)
