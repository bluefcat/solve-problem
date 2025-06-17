from itertools import product
MAX = 1_000_000
def get_result(arr, target):
    result = MAX
    l, r = 0, 1
    cnt = 0
    while r <= len(arr):
        if arr[r-1] == target:
            cnt += 1 

        while cnt >= 5 and l < r:
            if cnt == 5:
                result = min(result, r-l)
            cnt -= (arr[l] == target)
            l += 1

        r += 1
    return result




_ = input()
p = input().split()
c = {} 
result = MAX

for k in product(
    ["1", "2", "3", "4", "5", "6", "7", "8", "9"], ["m", "p", "s", "z"]
):
    result = min(result, get_result(p, ''.join(k)))

if result == MAX:
    print(-1)
    exit(0)
print(result)



