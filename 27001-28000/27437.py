def check(x, n) -> bool:
    return (n*(n-1) // 2) <= x

x = int(input()) - 1

yes, no = 1, 10**18

while yes + 1 < no:
    mid = (yes + no) >> 1
    if(check(x, mid)):
        yes = mid
    else:
        no = mid

s = x - ((yes - 1) * yes // 2)
if yes % 2 == 0:
    print(f"{s+1}/{yes-s}")
else:
    print(f"{yes-s}/{s+1}")

