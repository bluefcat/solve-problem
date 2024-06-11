import sys
from typing import TypeAlias
from enum import Enum
from collections import deque

class PuyoColor(Enum):
    empty  = 0
    red    = 1
    green  = 2
    blue   = 3
    yellow = 4
    purple = 5
    black  = 99

    def __repr__(self) -> str:
        return f"{self.value}"

string_to_color: dict[str, PuyoColor] = {
    ".": PuyoColor.empty,
    "R": PuyoColor.red,
    "G": PuyoColor.green,
    "B": PuyoColor.blue,
    "Y": PuyoColor.yellow,
    "P": PuyoColor.purple,
    "M": PuyoColor.black,
}

Coord: TypeAlias = tuple[int, int]
GroupIndex: TypeAlias = int

def get_group(
    field: list[list[PuyoColor]],
) -> dict[GroupIndex, list[Coord]]:
    result: dict[GroupIndex, list[Coord]] = {}

    index: GroupIndex = 0
    move = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    queue: deque[tuple[Coord, GroupIndex]] = deque()
    
    group: dict[Coord, GroupIndex] = {}

    queue.append(((0, 0), index))
    while queue:
        (x, y), idx = queue.popleft()
        group[(x, y)] = group.get((x, y), idx)
        group[(x, y)] = min(idx, group[(x, y)])

        for dx, dy in move:
            nx, ny = x+dx, y+dy
            if (nx < 0 or len(field[0]) <= nx) or \
               (ny < 0 or len(field) <= ny) or \
               (nx, ny) in group:
                continue

            if field[y][x] == field[ny][nx]:
                queue.appendleft(((nx, ny), idx))
            else:
                index += 1
                queue.append(((nx, ny), index))
    
    for k, v in group.items():
        result[v] = result.get(v, []) + [k]

    return result

def gravity(
    field: list[list[PuyoColor]]
):
    ground = [0 for _ in field[0]]
    check = [False for _ in field[0]]
    
    def get_index(x: int) -> int:
        return len(field) - (x+1)

    for h, row in enumerate(field[::-1]):
        for i, x in enumerate(row):
            if x == PuyoColor.empty:
                check[i] = True
                continue
            
            if check[i]:
                a, b= get_index(ground[i]), get_index(h)
                field[a][i], field[b][i] = \
                field[b][i], field[a][i]
            ground[i] += 1

def get_chain(
    field: list[list[PuyoColor]],
    chain: int = 4
) -> bool:
    is_chain = False
    group = get_group(field)
    for coords in group.values():
        x, y = coords[0]
        if field[y][x] == PuyoColor.empty or \
           len(coords) < chain:
            continue

        for x, y in coords:
            is_chain = True
            field[y][x] = PuyoColor.empty

    gravity(field)
    return is_chain


def main() -> int:
    input = sys.stdin.readlines
    field_str: list[str] = input()
    field: list[list[PuyoColor]] = [
        [string_to_color[word] for word in string.strip()]
        for string in field_str
    ]
    
    loop = True
    count = 0
    while loop:
        loop = get_chain(field)
        count += bool(loop)
    return count

print(main())

