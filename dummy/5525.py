n = int(input())
m = int(input())

target = input()
result = 0

proc = [[int("I" == x and "O" == y), 0] for x, y in zip(target, target[1:])]

for idx, _ in enumerate(proc[2:]):
    if proc[idx] != 0:
        proc[idx][0] += proc[idx-2][0]
        proc[idx][1] = int(target[idx] == "I")

for idx, (p, v) in enumerate(proc):
    if p >= n and target[idx+2] == "I":
        result += 1
        

print([x for x in target])
print([f'{x[0], x[1]}' for x in proc])
print(result)