import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, c = map(int, input().split())
    print(n//c + (n % c != 0))
