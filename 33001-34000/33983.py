import sys
from collections import deque
input = sys.stdin.readline 

o, h = deque(), deque()
_ = input()
target = input().strip()

for i, x in enumerate(target):
    if x == 'H':
        h.append((i, x))

    elif x == 'O':
        if h:
            h.popleft()
            o.append((i, 'K'))

        else:
            o.append((i, 'O'))
r = []

while o and h:
    if o[0][0] < h[0][0]:
        r.append(o.popleft()[1])
    else:
        r.append(h.popleft()[1])

while o:
    r.append(o.popleft()[1])

while h:
    r.append(h.popleft()[1])

s = []
for x in r:
    if not s:
        s.append(x)

    elif s[-1] == 'K' and x == 'H':
        s.pop()
    else:
        s.append(x)
if s:
    print("mix")
else:
    print("pure")
