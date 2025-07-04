F = 500501*50
cache = [0 for _ in range(F)]
_ = input()
arr = [*map(int, input().split())]
k = int(input())
r = 0

cache[0] = 0
for i in range(1, F):
    for x in arr:
        if i-x < 0:
            continue
        if cache[i] == 0:
            cache[i] = cache[i-x]+1
        cache[i] = min(cache[i-x]+1, cache[i])
    r = i
    if cache[i] > k:
        break


winner = "jjaksoon" if r & 1 else "holsoon"
print(f"{winner} win at {r}")
