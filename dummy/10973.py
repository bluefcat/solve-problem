from sys import stdin
from itertools import permutations
from random import shuffle
input = stdin.readline

n = int(input())
l = list(map(int, input().split()))


f = True
prev = sorted(l)

for i in permutations(sorted(l)):
    print(i)
    f = False
    prev = i