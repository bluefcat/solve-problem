import sys 
input = sys.stdin.readline
r,c,q = map(int, input().split())
field=[[0 for _ in range(c+1)]] + [[0]+[*map(int,input().split())] for _ in range(r)]

for i, row in enumerate(field[1:]):
    for j, _ in enumerate(row):
        field[i+1][j] += field[i][j]

for i, row in enumerate(field):
    for j, _ in enumerate(row[1:]):
        field[i][j+1] += field[i][j]

for _ in "*"*q:
    r1,c1,r2,c2=map(int, input().split())
    k = field[r2][c2] - field[r2][c1-1] - field[r1-1][c2] + field[r1-1][c1-1]
    a = (r2-(r1-1)) * (c2-(c1-1))
    print(k // a)
