_ = input()
arr = [*map(int, input().split())]

if len(arr) == 1:
    print(-1)
    exit(0)

result = [0 for _ in arr]
result[0] = 1
cnt = arr[0]

half = len(arr[::2]) - (len(arr) & 1)

for i in range(half):
    if arr[i] == cnt: #
        result[i] = 1
    else:
        result[i] = 0
        cnt -= 1

cnt = arr[len(arr)-1]
for i in range(half):
    if arr[len(arr)-1-i] == cnt: #
        result[len(arr)-1-i] = 0
    else:
        result[len(arr)-1-i] = 1
        cnt -= 1

rz = [x for x in result]
rz[half] = 0
ro = [x for x in result]
ro[half] = 1
def check(c, arr):
    z, o = [+(x==0) for x in arr], [+(x==1) for x in arr]
    z = z[::-1]
    for i, _ in enumerate(z[1:]):
        z[i+1] += z[i]

    for i, _ in enumerate(o[1:]):
        o[i+1] += o[i]
    z = z[::-1]
    return all([z[i] == c[i] if x == 1 else o[i] == c[i] for i, x in enumerate(arr)])

if not check(arr, rz) and not check(arr, ro):
    print(-1)
    exit(0)
if check(arr, rz):
    print(*rz)
    exit(0)

print(*ro)
