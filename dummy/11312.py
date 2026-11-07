t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    
    n = n // k
    k = 1

    print(sum([2*i+1 for i in range(n-k+1)]))