import sys
input = sys.stdin.readline

n = int(input())

result = 2

count = 1
change = False

for _ in range(n-1):
    result += count + 1
    
    if count % 2 == 1:
        count += 1
    
    else:
        if change:
            change = False
            count += 1
        else:
            change = True
        
print(result)