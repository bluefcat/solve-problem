import sys 
input = sys.stdin.readline
t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    if a == 0 and b != 0:
        print("no")

    else:
        print("yes")
    
