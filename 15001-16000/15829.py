n = int(input())
string = input()
result = 0

for i, x in enumerate(string):
	result += (ord(x)-ord('a')+1) * 31 ** i
	result %= 1234567891

print(result % 1234567891)
