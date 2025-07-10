state = [
    ["...."]*4, 
    ["****"]+["...."]*3,
    ["****"]*2+["...."]*2,
    ["****"]*3+["...."]*1,
    ["****"]*4,
]
score=[0,0,0,0,0]
m,_=map(int, input().split())
field=[input() for _ in range(5*m+1)]

for i, row in enumerate(field):
    for j, e in enumerate(row):
        
        for s, w in enumerate(state):
            f = all(
                all(
                    field[i+x][j+y] == c 
                    for y, c in enumerate(r) if 0 <= i+x < len(field) and 0 <= j+y < len(row)
                ) 
                for x, r in enumerate(w)
            )
            if f:
                score[s] += 1

print(*score)
