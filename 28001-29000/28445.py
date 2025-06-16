from itertools import product 
a, b = input().split()
c, d = input().split()
[print(x, y) for x, y in sorted([*product(set([a,b,c,d]), repeat=2)])]
