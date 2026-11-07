r, c = map(int, input().split())
a, b = map(int, input().split())

board = [[((i // b)+(j // a)) % 2 and "." or "X" for i in range(c*b)] for j in range(r*a)]

for b in board:
    print("".join(b))

