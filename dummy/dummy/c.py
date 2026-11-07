import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    x = input().strip()

    p = sum([e == '2' for e in x])
    q = sum([e == '3' for e in x])
    s = sum([int(e) for e in x])

    flag = False

    for i in range(0, p+1):
        for j in range(0, q+1):
            if flag:
                break
            if(s + 2*i + 6*j) % 9 == 0:
                print("YES")
                flag = True
                break
    if not flag:
        print("NO")
