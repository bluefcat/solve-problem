import sys 
input = sys.stdin.readline
_ = input()
arr = [*map(int, input().split())]
cnt = [0 for _ in range(11)]
l, r, result = 0, 0, 0
cnt[arr[l]] += 1

while True:
    tmp = [i for i, k in enumerate(cnt) if k != 0]
    if max(tmp) - min(tmp) <= 2:
        result = max(result, r-l+1)
        r += 1 
        if r >= len(arr):
            break
        cnt[arr[r]] += 1
    else:
        cnt[arr[l]] -= 1
        l += 1 


print(result)
