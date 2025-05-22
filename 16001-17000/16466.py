import sys 

input = sys.stdin.readline

_ = input() 
x = sorted([*map(int, input().split())])

result = 1 

for e in x:
    if e == result:
        result += 1 
    else:
        break

print(result)

