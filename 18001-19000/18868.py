import sys;input=sys.stdin.readline

def get(a):
    r = ''
    for i, _ in enumerate(a):
        for j, _ in enumerate(a):
            if i <= j:
                continue 
            r += f"{+(a[i] > a[j])}{+(a[i] == a[j])}"
    return f"{hex(int(r, 2))}"

n, _ = map(int, input().split())
x=[get([*map(int, input().split())]) for _ in '*'*n]
r = 0
for i, _ in enumerate(x):
    for j, _ in enumerate(x):
        if i <= j:
            continue 
        if x[i] == x[j]:
            r += 1
print(r)
