import sys
sys.setrecursionlimit(10**4)

MOD = 1000000
target = input() 

def solve(x):
    if x == "0":
        return 0

    if len(x) <= 1:
        return len(x)
    
    if x == "10":
        return 1

    if len(x) == 2 and x in [f"{i}" for i in range(11, 27)]:
        return 2
    
    result = (solve(x[0]) * solve(x[1:])) % MOD
    if x[0] == "1" or (x[0] == "2" and x[1] < "7"):
        result =  (result + solve(x[2:])) % MOD
    return result


print(solve(target))
