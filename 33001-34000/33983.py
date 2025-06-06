import sys
from collections import deque
input = sys.stdin.readline 

def merge(left, right, key):
    while left and right:
        if key(left[0]) < key(right[0]):
            yield left.popleft()
        else:
            yield right.popleft()
    
    k = left if left else right 
    while k:
        yield k.popleft()

o, h = deque(), deque()

_ = input()
target = input().strip()

for i, x in enumerate(target):
    if x == 'H':
        h.append((i, i, x))

    elif x == 'O':
        if h:
            l, *_ = h.popleft()
            o.append((l, i, 'K'))
        else:
            o.append((i, i, 'O'))

s = []
for x in merge(o, h, key=lambda x: x[1]):
    if s and s[-1][-1] == 'K' and x[-1] == 'H':
        print(s[-1], x)
        s.pop()
    else:
        s.append(x)

if s:
    print("mix")
else:
    print("pure")
