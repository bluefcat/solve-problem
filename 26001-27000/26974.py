import sys
input = sys.stdin.readline 

n = int(input())

result = [0]

diff = [*map(int, input().split())]
result.append(result[0] + diff[1])
m = result[0] + diff[1]

for idx in range(n-2):
    tmp = [*map(int, input().split())]
    tmp = tmp[1]
    
    if diff[idx+2] >= m:
        if (result[idx+1] + tmp) - min(result) == diff[idx+2]:
            result.append(result[idx+1] + tmp)
        else:
            result.append(result[idx+1] - tmp)
        m = diff[idx+2]
    else:
        result.append(result[idx+1] - tmp)

_ = input()

x = min(result)
if x < 0:
    result = [*map(lambda k: k+abs(x), result)]
print(*result)




