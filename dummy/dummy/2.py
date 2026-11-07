from collections import deque

pos = [[False for _ in range(10)] for _ in range(10)]

move = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

def is_in(n, x, y):
    return (0 <= x and x < n) and (0 <= y and y < n)

n = int(input())
r, c = map(int, input().split())

if n <= 5:
    result = 1
    pos[r-1][c-1] = True
    q = deque([(r-1, c-1)])

    while q:
        x, y = q.popleft()
        for m1 in move:
            dx1, dy1 = m1
            if not is_in(n, x+dx1, y+dy1):
                continue
            for m2 in move:
                dx2, dy2 = m2
                nx, ny = x+dx1+dx2, y+dy1+dy2
                if not is_in(n, nx, ny) or pos[nx][ny]:
                    continue
                pos[nx][ny] = True
                result += 1
                q.append((nx, ny))

    print(result)
else:
    if n % 2:
        print((n*n)//2 + (not ((r+c) % 2)))
    else:
        print((n*n)//2)