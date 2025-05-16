import sys 
input = sys.stdin.readline

def mpow(x, e):
    result = 1
    while(e):
        if(e & 1): result *= x
        x *= x
        e >>= 1
    return result

def get_count(n):
    result, s, e = 0, 0, 9
    for i in range(0, n):
        result += (i+1)*(e-s+1)
        s, e = e+1, e*10+9 
    return result

def check(pos, n) -> bool:
    return pos >= get_count(n)

def main():
    while True:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            return 0

        yes, no = 0, 10_000
        while yes + 1 < no:
            mid = (yes + no) >> 1 
            if(check(n, mid)):
                yes = mid
            else:
                no = mid
    
        diff = n - get_count(yes)
        idx = diff//(yes+1)
        if yes != 0:
            idx += mpow(10, yes)

        tar = f"{idx}"[diff%(yes+1):]
        i = 0
        while k != 0:
            print(tar[i] , end='')
            i += 1
            k -= 1
            if(i == len(tar)):
                i = 0 
                idx += 1 
                tar = f"{idx}"

        print()
main()


