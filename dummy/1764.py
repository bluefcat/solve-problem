n, m = map(int, input().split())
d = {}
for _ in range(n):
	key = input()
	d[key] = False
	
for _ in range(m):
	key = input()
	if key in d:
		d[key] = True
		
x = sorted([k for k, v in d.items() if v])
print(len(x))
for name in x:
	print(name)