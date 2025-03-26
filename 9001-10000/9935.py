##string = input()
string = "C" * 50000 + "4" * 50000
bomb = ["C", "4"] #[x for x in input()]
lb = len(bomb)
stack = []
size = 0

for w in string:
    stack.append(w)
    size += 1
    if size >= lb and all(x == y for x, y in zip(stack[-lb:], bomb)):
        stack = stack[:-lb]
        size -= lb

result = ''.join(stack)
if not result:
    print("FRULA")
else:
    print(result)

