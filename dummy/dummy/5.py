import sys
from collections import deque

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    p, q = map(int, input().split())

    print(f"{bin(p)[2:]:0>30}") 
    print(f"{bin(q)[2:]:0>30}")
    ...