n, b = map(int, input().split())
char = {10 + k: chr(v) for k, v in enumerate(range(ord('A'), ord('Z')+1))}
result = ""

while n:
    t = n % b
    if 0 <= t < 10:
        result += f"{t}"
    else:
        result += char[t]
    n //= b

print(result[::-1])
