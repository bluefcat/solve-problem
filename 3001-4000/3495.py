import sys
input = sys.stdin.readline

h, w = map(int, input().split())

result = 0

for _ in range(h):
    field = input().strip()
    is_in = False 

    for x in field:
        if x != '.':
            is_in ^= True
            result += 1
        elif is_in:
            result += 2

print(result // 2)
