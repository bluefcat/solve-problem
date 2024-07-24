def left(x):
    return (x << 1) + 1

def right(x):
    return (x << 1) + 2

def init(tree, string, sidx, eidx, idx):
    if sidx == eidx:
        if string[sidx] == '(':
            tree[idx] = 1
        else:
            tree[idx] = -1
        return tree[idx]

    midx = (sidx + eidx) >> 1
    l = init(tree, string, sidx, midx, left(idx))
    r = init(tree, string, midx+1, eidx, right(idx))
    
    tree[idx] = l+r    
    return tree[idx]

def query(tree, sidx, eidx, l, r, idx):
    if eidx < l or r < sidx:
        return 0
    if l <= sidx and eidx <= r:
       return tree[idx]
    midx = (sidx + eidx) >> 1
    le = query(tree, sidx, midx, l, r, left(idx))
    ri = query(tree, midx+1, eidx, l, r, right(idx))

    return le+ri

def main():
    le = 100000
    string = "(" * (le//2) + ")" * (le//2)
    string = "()" * (le//2)

    string = "()(())()"
    le = len(string)
    tree = ["" for _ in range(4*len(string))]

    init(tree, string, 0, len(string)-1, 0)
    result = 0
    for i in range(le):
        if i:
            r = query(tree, 0, len(string)-1, i, le-(i+1), 0)
            print(f"{r} {i}-{le-(i+1)}")
        result += int(
            query(tree, 0, len(string)-1, i, le-(i+1), 0) == 0
        )
    print(result)
main()
