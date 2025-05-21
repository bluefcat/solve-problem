t = [[*map(int, input().split())] for _ in range(3)]

for i in range(100):
    p, n = i % 3, (i+1) % 3
    
    cn = t[n][0]
    xp, xn = t[p][1], t[n][1]

    d = min(xp, cn-xn)
    t[p][1] -= d 
    t[n][1] += d



for i in range(3):
    print(t[i][1])

