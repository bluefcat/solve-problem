n, c = map(int, input().split())
l = list(map(int, input().split()))

result = 0
blood = 0
for idx, x in enumerate(l):
    blood += x
    if idx >= c:
        blood -= l[idx-c]
    if 129 <= blood and blood <= 138:
        result += 1

print(result)

