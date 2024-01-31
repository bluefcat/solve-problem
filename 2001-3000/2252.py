import sys 
from collections import deque

input = sys.stdin.read

n, m, *l = list(map(int, input().split()))

inorder, rinorder = {}, {}
graph = {}

for x, y in zip(l[::2], l[1::2]):
    inorder[y] = inorder.get(y, 0) + 1
    inorder[x] = inorder.get(x, 0)
    graph[x] = graph.get(x, []) + [y]
    graph[y] = graph.get(y, [])

queue = deque()

for k, v in inorder.items():
    rinorder[v] = rinorder.get(v, []) + [k]

while rinorder.get(0, False):
    queue.extend(rinorder[0])

    for k in rinorder[0]:
        inorder[k] -= 1

        for ki in graph[k]:
            inorder[ki] -= 1
    rinorder = {} 
    for k, v in inorder.items():
        rinorder[v] = rinorder.get(v, []) + [k]

    print(queue)
    print(inorder)
    print(rinorder)
    print(graph)
