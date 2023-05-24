n = 1000

result = [i for i in range(0, n)]

idx = 0
while(idx < len(result)):
	if(idx < 2):
		idx += 1
		continue
	x = result[idx]
	result = [i for i in result if i not in result[x::x]]
	idx += 1

print(result ,len(result))
