n = int(input())

answer = [0 for _ in range(1001)]

answer[1] = 0
answer[2] = 1
answer[3] = 0

for i in range(4, 1001):
    answer[i] = min(answer[i-3] + 1, answer[i-1]+1) % 2

print("CY" if answer[n] else "SK")
