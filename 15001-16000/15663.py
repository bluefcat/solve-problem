import sys
from itertools import permutations

input = sys.stdin.readline

def main():
    check = {}
    _, m = map(int, input().strip().split())
    l = list(map(int, input().strip().split()))
    l = sorted(l) 
    for x in permutations(l, m):
        check[x] = check.get(x, False)
        if check[x]:
            continue
        check[x] = True
        print(' '.join(map(str, x)))

main()

