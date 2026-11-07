from itertools import combinations

#w, p = map(int, input().split())
#part = [0] + list(map(int, input().split())) + [w]
w, p = 50, 50
part = [0] + [i for i in range(1, w)] + [w]
tmp = []

for px, x in zip(part[0:], part[1:]):
    tmp.append(x-px)

result = set()

for l, x in enumerate(tmp):
    for y in combinations(tmp, l+1):
        result.add(sum(y))


result = sorted(list(result))
for x in result:
    print(x, end=' ')
print()