from enum import Enum
class Dir(Enum):
    M, U, L, D, R = 0, 1, 2, 3, 4 

def candidate(x, y):
    dx = [0, 4, 3, 1, 2, 0] #MRDULM
    dy = [0, 1, 4, 2, 3, 0] #MURLDM
    ax, ay = x, y
    if x < 0:
        ax, dx = abs(x), dx[::-1]
    if y < 0:
        ay, dy = abs(y), dy[::-1]
    pos = dy[(ay + dy.index(dx[ax % 5])) % 5]
    cor = {
        0: lambda x, y: (x, y),
        1: lambda x, y: (x, y-1),
        2: lambda x, y: (x+1, y),
        3: lambda x, y: (x, y+1),
        4: lambda x, y: (x-1, y)
    }
    return cor[pos](x, y)


x0, y0 = map(int, input().split())
x1, y1 = map(int, input().split())

mx = min(x0, x1)
my = min(y0, y1)

x = candidate(x0, y0)
y = candidate(x1, y1)

print(x, y)
if x == y:
    print(0)
    exit(0)

dx, dy = y[0] - x[0], y[1] - x[1]
print(dx, dy)

kx, ky = 2*dx + dy, dx - 2*dy

print(kx, ky)
print(abs(kx//5) + abs(ky//5))





