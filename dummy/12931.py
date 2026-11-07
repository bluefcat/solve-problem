_ = input()
B = list(map(int, input().split()))

result = 0

while any([i != 0 for i in B]):
    if all([i % 2 == 0 for i in B]):
        B = [i // 2 for i in B]

        result += 1
    
    for i, x in enumerate(B):
        if x % 2 != 0:
            B[i] -= 1
            result +=1

print(result)