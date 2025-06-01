import sys 
input = sys.stdin.readline
n = int(input())
a = sorted([*map(int, input().split())])[n:2*n]
print(max(a)-min(a))

