import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

a = input().rstrip()
b = input().rstrip()

cache = [[0 if (x == 0 or y == 0) else -1 for y, _ in enumerate(b + " ")] for x, _ in enumerate(a + " ")]

def solve(x, y):
    if cache[x][y] != -1:
        return cache[x][y]

    cache[x][y] = max(solve(x-1, y), solve(x, y-1), cache[x-1][y-1] + int(a[x-1] == b[y-1]))
    return cache[x][y]

print(solve(len(a), len(b)))
