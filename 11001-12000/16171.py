import sys
input = sys.stdin.readline

x = input().strip()
y = input().strip()

x = ''.join([c for c in x if not (ord('0') <= ord(c) <= ord('9'))])
print(+(y in x))
