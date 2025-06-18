f = {
    "R": {"R": 0, "P": -1, "S": 1},
    "P": {"R": 1, "P": 0, "S": -1},
    "S": {"R": -1, "P": 1, "S": 0},

}

ml,mr,tl,tr = input().split()
m,t=[ml,mr],[tl,tr]

if any(all(f[x][y] == 1 for y in t) for x in m):
    print("MS")
    exit(0)

if any(all(f[x][y] == 1 for y in m) for x in t):
    print("TK")
    exit(0)

print("?")
