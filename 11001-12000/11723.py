n = int(input())

s = set()

for i in range(n):
	a = input()

	oper, n = '', ''
	if ' ' in a:
		oper, n = a.split()
	else:
		oper = a
	
	if oper == "add":
		s.add(n)
	elif oper == "remove":
		if n in s:
			s.remove(n)
	elif oper == "check":
		print(int(n in s))
	elif oper == "toggle":
		if n in s:
			s.remove(n)
		else:
			s.add(n)
	elif oper == "all":
		s = {str(i) for i in range(1, 21)}
	elif oper == "empty":
		s = set()
	else:
		continue

