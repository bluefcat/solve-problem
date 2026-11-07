import sys
input = sys.stdin.read

n = int(input())

width = 3 + 2 * (n-1 + max(n-2, 0))
height = 3 + 4 * (n-1) 

field = [[' ' for _ in range(width)] for _ in range(height)]

pos = [0, width - 1] # y, x
move, current = [[0, -1], [1, 0], [0, 1], [-1, 0]], 0

wall = [[0, width], [0, height]]

narrowing = False

while wall[0][0] < wall[0][1]:
    # draw
    y, x = pos
    field[y][x] = '*'

    # move
    pos = [p + m for p, m in zip(pos, move[current])]

    limit_min, limit_max = wall[current & 1]
    moving_pos = pos[(current + 1) & 1]
    if (moving_pos < limit_min) or (limit_max <= moving_pos):
        pos[(current + 1) & 1] = max(limit_min, min(limit_max-1, moving_pos))
        current = (current + 1) % len(move)

        if current == 0 and narrowing:
            wall[0][0] += 2
        
        if current == 1 and narrowing:
            wall[1][1] -= 2

        if current == 2 and narrowing:
            wall[0][1] -= 2

        if current == 3:
            wall[1][0] += 2
            narrowing = True

if n != 1:
    print('\n'.join([''.join(row).rstrip() for row in field]))

else:
    print("*")