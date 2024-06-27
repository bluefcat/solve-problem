import sys
input = sys.stdin.readline

def get_parent(d: dict, name: str) -> str:
    if d[name] == name:
        return name

    d[name] = get_parent(d, d[name])
    return d[name]

def union(d: dict, x: str, y: str) -> None:
    px = get_parent(d, x)
    py = get_parent(d, y)
    target = py
    if px < py:
        target = px
    
    d[px] = target
    d[py] = target

def main():
    t = int(input().strip()) 

    while t:
        t -= 1
        network = {}
        n = int(input().strip())
        for _ in range(n):
            x, y = input().strip().split() 
            if x not in network:
                network[x] = x
            if y not in network:
                network[y] = y
            union(network, x, y)
            
            root = get_parent(network, x)
            print(sum(get_parent(network,y) == root for _, y in network.items()))

main()
