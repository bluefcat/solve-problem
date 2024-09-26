from collections import deque

T = int(input())

for _ in range(T):
    P = input()
    n = int(input())
    content = input()[1:-1]
    if not content:
        arr = deque([])
    else:
        arr = deque(map(int, (content).split(',')))
    for oper in P:
        if oper == 'R':
            arr.reverse()
        elif oper == 'D':
            if not arr:
                print("error")
                break
            else:
                arr.popleft()
    else:
        result = ",".join(map(str, arr))
        print(f"[{result}]")


