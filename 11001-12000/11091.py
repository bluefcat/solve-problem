import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    d = {chr(ord('a')+i): 0 for i in range(0, 26)}
    x = input()

    for c in x.lower():
        if c in d:
            d[c] = 1

    if sum(d.values()) == 26:
        print("pangram")
    else:
        print("missing ", end='')
        for x in d.keys():
            if d[x] == 0:
                print(x, end='')
        print()

