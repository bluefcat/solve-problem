import sys 
input = sys.stdin.readline 

def get_floor(x):
    yes, no = 0, 62
    while yes+1 < no:
        mid = (yes+no) >> 1
        if 2**mid <= x: yes = mid 
        else: no = mid

    return yes+1

for _ in range(int(input())):
    n = int(input())
    x = get_floor(n)
    while x > 0:
        k = n-2**(x-1)+1
        print(f"{x}{k:>018}")
        n >>= 1
        x -= 1
