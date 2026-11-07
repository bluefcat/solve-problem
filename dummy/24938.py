N = int(input())
arr = list(map(int, input().split()))

result = 0
avg = sum(arr)//N

for i, _ in enumerate(arr[:N-1]):
    if arr[i] < avg:
        diff = avg - arr[i]
        arr[i], arr[i+1] = avg, arr[i+1] - diff
        result += diff
        
    elif arr[i] > avg:
        diff = arr[i] - avg
        arr[i], arr[i+1] = avg, arr[i+1] + diff
        result += diff

print(result)