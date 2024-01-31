from enum import Enum
from typing import Any, TypeAlias, Optional, cast

Pos: TypeAlias = tuple[int, int]

class Rotation(Enum):
    NONE = 0
    CLOCKWISE = 1
    COUNTERWISE = 2

class Direction(Enum):
    UP = 0
    LEFT = 1
    DOWN = 2
    RIGHT = 3
    @staticmethod
    def pos(direction: "Direction") -> Pos:
        result: list[Pos] = [(0, -1), (-1, 0), (0, 1), (1, 0)] 
        return result[direction.value]
    
    @staticmethod
    def rotate(direction: "Direction", rotation: Rotation) -> "Direction":
        if rotation == Rotation.COUNTERWISE:
            return Direction((direction.value + 1) % 4)

        if rotation == Rotation.CLOCKWISE:
            return Direction((direction.value + 3) % 4)

        return direction


class Kind(Enum):
    BLOCK = 0
    ITEM = 1
    SNAKE = 2

class Game:
    def __init__(self):
        self.timer: int = 0
        self.positions: dict[int, Pos] = {}
        self.objects: dict[Pos, "Object"] = {}    
        self.snake: list["Snake"] = []    

    def get_head(self) -> "Snake":
        return self.snake[-1]

    def append(self, obj: "Object", pos: Pos):
        self.positions[obj.uid] = pos
        self.objects[pos] = obj
        self.snake.append(cast("Snake", obj))

    def move(self, uid: int, dx: int, dy: int):
        x, y = self.positions[uid]
        obj = self.objects[(x, y)]
    
        nx, ny = x+dx, y+dy

        
        # updating
        obstacle = self.objects.get((nx, ny), None)

        if obstacle and obstacle.kind == Kind.ITEM:
            cast("Snake", obj).item = True
            head = Snake(obj.uid+1, self, cast("Snake", obj))
            cast("Snake", obj).rotation = Rotation.NONE
            head.direction = cast("Snake", obj).direction
            self.append(head, (nx, ny))
            return

        elif obstacle:
            #GAMEOVER
            ...
            
        del self.positions[uid]
        del self.objects[(x, y)]
        self.positions[uid] = (nx, ny)
        self.objects[(nx, ny)] = obj

    def print(self):
        for i in range(6):
            for j in range(6):
                obj = self.objects.get((i, j), None)
                if obj:
                    print(obj.uid, end=" ")
                else:
                    print(" ", end=" ")

            print()


class Object:
    def __init__(self, uid: int, kind):
        self.uid = uid
        self.kind = kind

    def __eq__(self, other) -> bool:
        return self.uid == other.uid

class Snake(Object):
    def __init__(self, uid: int, game: Game, follower: Optional["Snake"]):
        super().__init__(uid, Kind.SNAKE)

        self.direction: Direction = Direction.RIGHT
        self.rotation = Rotation.NONE
        self._rotation = Rotation.NONE
        self.game = game
        self.follower = follower
        
        self.item = False

    def move(self):
        self._rotation = self.rotation
        self.direction = Direction.rotate(
            self.direction,
            self._rotation
        ) 
        dy, dx = Direction.pos(self.direction)
        
        # field update
        self.game.move(self.uid, dx, dy)

        if self.item:
            self.item = False
            return

        if self.follower:
            self.follower.move()
            self.follower.rotation = self._rotation

        self.rotation = Rotation.NONE

def main():
    game = Game()
    head = Snake(1, game, None)
    
    item = Object(0, Kind.ITEM)

    game.append(item, (3, 3))
    game.append(item, (1, 1))
    game.append(head, (0, 0))

    count = 0

    while True:
        game.print()    
        c = input()
        
        if c == '0':
            game.get_head().move()
        elif c == '1':
            game.get_head().rotation = Rotation.CLOCKWISE
        else:
            game.get_head().rotation = Rotation.COUNTERWISE

main()

