import sys
import math
input = sys.stdin.readline
flush = sys.stdout.flush

m = [2**i for i in range(41)]
a = [0 for _ in m]
#query
for i, e in enumerate(m):
    print(f"? {e}")
    flush()
    a[i] = int(input())

result = math.gcd(*[x-y for x, y in zip(m, a) if x-y])

print(f"! {result}")
flush()
