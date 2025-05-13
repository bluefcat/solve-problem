import sys
input = sys.stdin.readline
f = {"A": "C", "C": "G", "G": "T", "T": "A"}

x = input().strip()
y = ''.join(map(lambda x: f[x], x))

for l, _ in enumerate(y + '0'):
    if not l:
        continue
    for dy in range(len(y)-l+1):
        if not y[dy:l+dy] in x:
            print(y[dy:l+dy])
            exit(0)

