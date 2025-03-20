import sys

input = sys.stdin.readline

L = 1_000_000_000+1
_ = input()

print(f"? {L}")
sys.stdout.flush()
y = int(input())
result = []

while y:
    result.append(y % L)
    y //= L

x = ' '.join(map(str, result))
print(f'! {x}')
sys.stdout.flush()
