import sys 
input = sys.stdin.readline
_ = input()
arr = [*map(int, input().split())]
l, r, result = 0, 0, 0

while r < len(arr):
    if abs(arr[r] - arr[l]) <= 2:
        result = max(result, r-l+1)
        r += 1 
    else:
        l += 1

print(result)
