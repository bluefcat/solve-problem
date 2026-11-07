import sys
import math

L = 4 * (10 ** 6) + 1
input = sys.stdin.readline

n, k, m = map(int, input().split())
print(math.comb(n, k) % m)