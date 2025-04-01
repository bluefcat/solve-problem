import sys

input = sys.stdin.readline

n = int(input())

n = int(bin(n)[2:][::-1], 2)
print(n)
