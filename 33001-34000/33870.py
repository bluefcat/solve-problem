n, m = map(int, input().split())
a = [*map(int, input().split())]
b = [*map(int, input().split())] + [-1]

d = [[0, 0] for _ in a]

for idx in b:
    for i, _ in enumerate(a):
        match d[i][1]:
            case 0:
                d[i][0] += 1
                if d[i][0] > a[i]:
                    d[i][0], d[i][1] = 0, 2
                if i == idx-1:
                    d[i][0] = 0
                    d[i][1] = max(d[i][1]-1, 0)
            case 1:
                if i == idx-1:
                    d[i][1] -= 1
                if i != idx-1:
                    d[i][1] = 2
            case 2:
                if i == idx-1:
                    d[i][1] -= 1
print(sum(x != 0 for _, x in d))
