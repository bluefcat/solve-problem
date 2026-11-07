import sys

input = sys.stdin.readline

n, q = map(int, input().split())
data = {}

for _ in range(n):
    k, v = input().split()
    data[k.strip()] = v.strip()

for _ in range(q):
    print(data[input().strip()])