import sys

input = sys.stdin.readline

def get_v(c, t, v0):
    return (2*c*t + (v0*v0))**0.5

n, C = map(int, input().split())

v0s = []

for _ in range(n):
    v, _, _ = map(int, input().split())
    v0s.append(v)

v0s = sorted(v0s)

q = int(input())

for _ in range(q):
    t, k = map(int, input().split())
    k -= 1

    print(f"{get_v(C, t, v0s[k]):.5f}")

