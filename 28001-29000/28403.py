import sys 
input = sys.stdin.readline 

def get_result(arr, s = 0, p = 0, k = 0):
    if len(arr) <= s+k-1:
        return 0
    if arr[s+k-1]-p == k:
        return 1
    return 1+get_result(arr, s+k, arr[s+k-1], k-(arr[s+k-1]-p))


_ = input() 
deck = [*input().strip()]
acc = [+('S' == card) for card in deck]

for i, _ in enumerate(acc[1:]):
    acc[i+1] += acc[i]

print(*[get_result(acc, 0, 0, k) for k in range(1, len(deck)+1)])
