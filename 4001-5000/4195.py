import sys
input = sys.stdin.readline

def get_parent(d: list, name: int) -> int:
    if d[name] == name:
        return name

    d[name] = get_parent(d, d[name])
    return d[name]

def union(d: list, n: list, x: int, y: int) -> None:
    px = get_parent(d, x)
    py = get_parent(d, y)
    if px == py:
        return
    p, target = px, py
    if px < py:
        p, target = py, px
    
    d[p] = target
    n[target] += n[p]

def main():
    t = int(input().strip()) 

    while t:
        t -= 1
        f = {}
        cnt = 0
        network = [i for i in range(100001)]
        fc = [1 for _ in range(100001)]
        n = int(input().strip())
        for _ in range(n):
            x, y = input().strip().split() 
            f[x] = f.get(x, cnt); cnt += 1
            f[y] = f.get(y, cnt); cnt += 1
            union(network, fc, f[x], f[y])
            root = get_parent(network, f[x])
            print(fc[root])


main()
