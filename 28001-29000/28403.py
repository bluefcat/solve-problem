import sys 
input = sys.stdin.readline 

def get_result(arr, s = 0, p = 0, k = 0):
    result = 0
    while len(arr) > s+k-1:
        if arr[s+k-1]-p == k:
            return result+1
        result += 1 
        s, k, p = s+k, k-(arr[s+k-1]-p), arr[s+k-1] 
    return result

_ = input() 
deck = [*input().strip()]
acc = [+('S' == card) for card in deck]

for i, _ in enumerate(acc[1:]):
    acc[i+1] += acc[i]

print(*[get_result(acc, 0, 0, k) for k in range(1, len(deck)+1)])
