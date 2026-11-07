import sys
input = sys.stdin.readline
L = 5001
P = 1000000007

cache = [0 for _ in range(L)]
cache[0] = 1

for i in range(L):
    if i % 2 == 0:
        cache[i] = sum([cache[i-j] for j in range(0, i, 2)]) + 1
        
    


t = int(input())

for _ in range(t):
    n = int(input())
    print(cache[n])    

