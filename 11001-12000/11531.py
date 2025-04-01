import sys
input = sys.stdin.readline

d = {}

while True:
    log = input()
    if log[0] == '-':
        break

    t, n, a = log.split()
    if a == "right":
        d[n] = d.get(n, [0, 0, False])
        d[n][0] = int(t)
        d[n][2] = True

    else:
        d[n] = d.get(n, [0, 0, False])
        d[n][1] += 1
print(sum([z for _, _, z in d.values()]), sum([x+20*y for x, y, z in d.values() if z]))
