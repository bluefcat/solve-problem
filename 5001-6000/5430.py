import sys
from collections import deque

input = sys.stdin.readline

T = int(input().strip())

for _ in range(T):
    P = input().strip()
    n = int(input().strip())
    content = input().strip()[1:-1]
    r = False
    if not content:
        arr = deque([])
    else:
        arr = deque(map(int, (content).split(',')))
    for oper in P:
        if oper == 'R':
            r ^= True
        elif oper == 'D':
            if not arr:
                print("error")
                break
            else:
                if r:
                    arr.pop()
                else:
                    arr.popleft()
    else:
        if r:
            arr.reverse()
        result = ",".join(map(str, arr))
        print(f"[{result}]")


