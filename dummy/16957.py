import sys
input = sys.stdin.readline

r, c = map(int, input().split())

field_ = []
cache_ = []
result = []

for _ in range(r):
    row = list(map(int, input().split()))
    field_.append(row)
    result.append([0 for _ in row])

def is_vertical_edge(field, x):
    return not (0 <= x < len(field))

def is_horizontal_edge(field, y):
    return not (0 <= y < len(field[0]))

def check_min(field, x, y):
    result = (x, y)
    cur = field[x][y]

    move = [[1, 0], [0, 1], [-1, 0], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1]]
    
    for m in move:
        nx, ny = x + m[0], y + m[1]

        if is_vertical_edge(field, nx) or is_horizontal_edge(field, ny):
            continue

        if cur > field[nx][ny]:
            result = (nx, ny)
            cur = field[nx][ny]

    return result

for x, row in enumerate(field_):
    cache_.append([check_min(field_, x, y) for y, _ in enumerate(row)])


for x, row in enumerate(cache_):
    for y, e in enumerate(row):
        px, py = e
        nx, ny = cache_[px][py]

        while (cache_[x][y][0] != nx) or (cache_[x][y][1] != ny):
            nx, ny = cache_[nx][ny]
            cache_[x][y] = (nx, ny)

for x, row in enumerate(cache_):
    for y, e in enumerate(row):
        px, py = e
        nx, ny = cache_[px][py]

        while (cache_[x][y][0] != nx) or (cache_[x][y][1] != ny):
            nx, ny = cache_[nx][ny]
            cache_[x][y] = (nx, ny)
        result[nx][ny] += 1
for r in result:
    print(' '.join(map(str, r)))
