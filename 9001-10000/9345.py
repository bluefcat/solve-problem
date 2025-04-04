import sys
input = sys.stdin.readline
N = 4 * 100_001 + 4
seg = [
    [0, 0] for _ in range(N)
] + [[9999999999999, -1]]

arr = [i for i in range(0, N+1)]

def get_left(x):
    return (x << 1) + 1

def get_right(x):
    return (x << 1) + 2

def init(l, r, idx):
    if l == r:
        seg[idx][0], seg[idx][1] = arr[l], arr[l]
        return idx

    m = (l + r) >> 1
    li, ri = init(l, m, get_left(idx)), init(m+1, r, get_right(idx))
    seg[idx][0] = min(seg[li][0], seg[ri][0])
    seg[idx][1] = max(seg[li][1], seg[ri][1])
    return idx

def query(l, r, s, e, idx):
    if r < s or e < l:
        return seg[N]

    if s <= l and r <= e:
        return seg[idx]

    m = (l + r) >> 1
    lm, lM = query(l, m, s, e, get_left(idx))
    rm, rM = query(m+1, r, s, e, get_right(idx))

    return [min(lm, rm), max(lM, rM)]


def update(l, r, x, v, idx):
    if x < l or r < x:
        return idx

    if l == r:
        seg[idx][0], seg[idx][1] = v, v
        return idx 

    m = (l + r) >> 1

    li = update(l, m, x, v, get_left(idx))
    ri = update(m+1, r, x, v, get_right(idx))

    seg[idx][0] = min(seg[li][0], seg[ri][0])
    seg[idx][1] = max(seg[li][1], seg[ri][1])

    return idx


T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    for i in range(N):
        arr[i] = i

    init(0, n-1, 0)

    for _ in range(k):

        oper, a, b = map(int, input().split())

        match oper:
            case 0:
                update(0, n-1, a, arr[b], 0)
                update(0, n-1, b, arr[a], 0)
                arr[a], arr[b] = arr[b], arr[a]

            case 1:
                m, M = query(0, n-1, a, b, 0)
                if m == a and M == b:
                    print("YES")
                else:
                    print("NO")



