import asyncio
from itertools import product 
class Unit:
    def __init__(self):
        self.flag = False
        self.func = (lambda _: self.flag)

    def is_valid(self, board):
        return not(self.flag ^ self.func(board))

class Board:
    def __init__(self):
        self.board = {}
        self._eval = False
        self.bingo = [0, 0, 0, 0]
        self.colored = set()
        self.colored_bingo = set()
        self.colored_unbingo = set()
        
        for x, y in product(
            ['a', 'b', 'c', 'd', 'e'], 
            ['1', '2', '3', '4', '5']
        ):
            self.board[x] = self.board.get(x, {})
            self.board[x][y] = Unit()

    def eval(self):
        if self._eval:
            return
        self._eval = True
        self.bingo = [0, 0, 0, 0]
        self.colored = set()
        self.colored_bingo = set()
        self.colored_unbingo = set()

        for x in ['a', 'b', 'c', 'd', 'e']:
            if self.get_col(x):
                self.bingo[0] += 1
                for y in ['1', '2', '3', '4', '5']:
                    self.colored_bingo.add(f"{x}{y}")

        for y in ['1', '2', '3', '4', '5']:
            if self.get_row(y):
                self.bingo[1] += 1
                for x in ['a', 'b', 'c', 'd', 'e']:
                    self.colored_bingo.add(f"{x}{y}")

        if self.get_dig():
            self.bingo[2] += 1
            for u, v in zip(
                ['a', 'b', 'c', 'd', 'e'],
                ['1', '2', '3', '4', '5']
            ):
                self.colored_bingo.add(f"{u}{v}")

        if self.get_rig():
            self.bingo[3] += 1
            for u, v in zip(
                ['a', 'b', 'c', 'd', 'e'],
                ['5', '4', '3', '2', '1']
            ):
                self.colored_bingo.add(f"{u}{v}")

        for x, y in product(
            ['a', 'b', 'c', 'd', 'e'], 
            ['1', '2', '3', '4', '5']
        ):
            if self.board[x][y].flag:
                self.colored.add(f"{x}{y}")

        self.colored_unbingo = self.colored - self.colored_bingo

    def get_col(self, key):
        return all([u.flag for u in self.board[key].values()])

    def get_row(self, key):
        return all([self.board[c][key].flag for c in ['a', 'b', 'c', 'd', 'e']])

    def get_dig(self):
        return all([
            self.board[u][v].flag for u, v in zip(
                ['a', 'b', 'c', 'd', 'e'],
                ['1', '2', '3', '4', '5']
            )
        ])

    def get_rig(self):
        return all([
            self.board[u][v].flag for u, v in zip(
                ['a', 'b', 'c', 'd', 'e'],
                ['5', '4', '3', '2', '1']
            )
        ])

    def is_valid(self):
        return all([
            all([
                u.is_valid(self) for u in row.values()
            ]) for row in self.board.values()
        ])

    def __getitem__(self, key):
        return self.board[key]

def set_logic(b):
    b['a']['1'].func = (lambda board: not board.bingo[3] == 1)
    b['b']['1'].func = (lambda board: 'b1' not in board.colored_bingo)
    b['c']['1'].func = (lambda board: board.bingo[2] == 1)
    b['d']['1'].func = (lambda board: 'd4' in board.colored)
    b['e']['1'].func = (lambda board: 'e1' in board.colored_bingo)

    b['a']['2'].func = (lambda board: 'a4' not in board.colored)
    b['b']['2'].func = (lambda board: all([board.bingo[0] >= 1 and board.bingo[1] >= 1 and (board.bingo[3] >= 1 or board.bingo[2] >= 1)]))
    b['c']['2'].func = (lambda board: board['c']['2'].flag)
    b['d']['2'].func = (lambda board: len(board.colored) <= 17)
    b['e']['2'].func = (lambda board: len(board.colored_bingo) % 2 == 0)

    b['a']['3'].func = (lambda board: 'a3' in board.colored_bingo)
    b['b']['3'].func = (lambda board: len(board.colored_unbingo) >= 5)
    b['c']['3'].func = (lambda board: ('c3' not in board.colored) or ('c3' in board.colored_bingo))
    b['d']['3'].func = (lambda board: board.bingo[0] >= 2)
    b['e']['3'].func = (lambda board: 15 >= len(board.colored_bingo))

    b['a']['4'].func = (lambda board: 'a2' not in board.colored)
    b['b']['4'].func = (lambda board: board.get_row('2') or board.get_col('d'))
    b['c']['4'].func = (lambda board: sum([v.flag == True for v in board['c'].values()]) <= 3)
    b['d']['4'].func = (lambda board: "d1" in board.colored)
    b['e']['4'].func = (lambda board: board.bingo[2]+board.bingo[3] >= 1)

    b['a']['5'].func = (lambda board: 'e5' in board.colored)
    b['b']['5'].func = (lambda board: board['b']['5'].flag)
    b['c']['5'].func = (lambda board: board['c']['5'].flag)
    b['d']['5'].func = (lambda board: sum(board.bingo) >= 3)
    b['e']['5'].func = (lambda board: 'a5' in board.colored)

async def run(b, s, e, step =1):
    for idx in range(s, e, step):
        for i in range(0, 25):
            r, c = i // 5, i % 5
            b[chr(ord('a')+r)][f'{c+1}'].flag = ((idx & (1 << i)) == (1 << i))

        b._eval = False
        b.eval()

        if b.is_valid():
            for y in ['1', '2', '3', '4', '5']:
                for x in ['a', 'b', 'c', 'd', 'e']:
                    print(int(b[x][y].flag), end=' ')
                print()
            print("=====")

async def main():

    b0 = Board()
    set_logic(b0)

    await run(b0, (1<<25)-1, 0, -1)

    return

if __name__ == "__main__":
    asyncio.run(main())
