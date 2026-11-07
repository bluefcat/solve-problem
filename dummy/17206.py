T = input()
N = list(map(int, input().split(" ")))


cache = [0 for _ in range(80001)]
i = 1
for x in range(1, 80001):
    if x % 7 == 0 or x % 3 == 0:
        cache[i] = cache[i-1] + x
    else:
        cache[i] = cache[i-1]
    
    i += 1

for n in N:
    print(cache[n])