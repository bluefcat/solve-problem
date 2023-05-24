n = int(input())
x = list(map(int, input().split()))
y = {v: k for k, v in enumerate(sorted(list(set(x))))}

[print(y[i], end=' ') for i in x]
print()
