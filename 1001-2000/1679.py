_ = input()
arr = sorted([*map(int, input().split())])
k = int(input())
r = 0

def sum_n(n, p, k):
    count = {x: 0 for x in p}
    
    while True:
        count[p[0]] += 1
        for x,y in zip(p, p[1:]):
            if count[x] > k:
                count[x] = 0
                count[y] += 1
            if y > n:
                break
            else:
                break

        if count[p[-1]] >= k + 1:
            return None
        
        if sum(count.values()) > k:
            continue 

        if n == sum(k*v for k, v in count.items()):
            return count

    

def find(p, k):
    n = 1

    while sum_n(n, p, k):
        n += 1
    
    return n

ans = find(arr, k)
winner = "holsoon" if k & 1 else "jjaksoon"
print(f"{winner} win at {ans}")
