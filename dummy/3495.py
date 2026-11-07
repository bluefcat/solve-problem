import sys
input = sys.stdin.readline

h, w = map(int, input().split())
field = []

for _ in range(h):
    field.append(input().strip())

result = [0, 2]

for row in field:
    is_in = False

    for x in row:
        
        if x != '.':
            is_in ^= True
            result[0] += 1

        elif is_in:
            result[0] += 2

print(result[0] // result[1])
