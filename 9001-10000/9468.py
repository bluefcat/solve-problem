import sys 
input = sys.stdin.readline 

n = int(input())

for _ in range(n):
    idx, *arr = [*map(int, input().split())]
    flag = {x: False for x in range(8)}

    result = 0
    
    for i in arr:
        if not flag[i]:
            flag[i] = True 
            result += (i != 0)

        elif flag[i+1]:
            flag[i+1] = False

    print(idx, result)
