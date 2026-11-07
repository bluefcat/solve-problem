n = int(input())
l = list(map(int, input().split()))

l = sorted(l)
result = 1
capa = l[0]

for x in l[1:]:
    capa = min(capa-1, x)
    if(capa == 0):
        result += 1
        capa = x

print(result)