E = 0.0000001
def dist(x0, y0, x1, y1):
    return ((x0-x1)**2 + (y0-y1)**2)**(0.5)

ax, ay, bx, by, cx, cy, dx, dy = map(int, input().split())

lx, kx = ((bx-ax)-(dx-cx)), (ax-cx)
ly, ky = ((by-ay)-(dy-cy)), (ay-cy)

if -E < lx < E and -E < ly < E:
    print(f"{dist(ax, ay, cx, cy):.10f}")
    exit(0)

t = min(1, max(0, -(lx*kx+ly*ky)/(lx**2+ly**2)))

result = dist(
    (bx-ax)*t+ax, (by-ay)*t+ay,
    (dx-cx)*t+cx, (dy-cy)*t+cy
)

print(f"{result:.10f}")
