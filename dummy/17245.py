#n = int(input())
print("A")
n = 1000
field = []

for _ in range(n):
    field.append([10000000 for _ in range(n)])
    #field.append(list(map(int, input().split())))


half = sum([sum(f) for f in field]) / 2
max_height = max([max(f) for f in field])
count = 0

unit = n ** 2
height = sum([sum(f) for f in field]) / unit

while height <= max_height:
    count = sum([sum([height >= x and x or max(0, height) for x in f if x != 0]) for f in field])
    
    if: 
    elif:
    else:

    height += 1

print(f"{height}")
    