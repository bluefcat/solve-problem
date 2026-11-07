from collections import deque

n = int(input())
x = list(map(int, input().split()))

#n = 100000
#x = [2 for _ in range(n-1)] + [1]

top = None
result = deque()

for idx, op in enumerate(x[::-1]):
    if op == 1:
        if not top:
            top = idx+1
        else:
            result.appendleft(top)
            top = idx + 1
    elif op == 2:
        result.appendleft(idx+1)
    else:
        result.append(idx+1)

print(top, end=' ')
for r in result:
    print(r, end=' ')
print()
        