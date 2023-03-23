import math
min_n, max_n = map(int, input().split())
result = [i for i in range(min_n, max_n+1)]
x = 2
tmp = set()
while(x**2 <= max_n):
	tmp |= set(result[math.ceil(min_n/x**2)*x**2-min_n::x**2])
	x += 1
print(len(result)-len(tmp))
