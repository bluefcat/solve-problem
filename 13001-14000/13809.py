import sys 
input = sys.stdin.readline

def mpow(x, e):
    result = 1
    while(e):
        if(e & 1): result *= x
        x *= x
        e >>= 1
    return result

def check(pos, n) -> bool:
    result = 10
    tmp = 110
    for i in range(2, n+1):
        result += i*tmp;
        tmp *= 110

    return pos < result

def main():
    while True:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            return 0

        no, yes = 0, 10_000
        while no + 1 < yes:
            mid = (yes + no) >> 1 
            if(check(n, mid)):
                yes = mid
            else:
                no = mid

        cnt = 0 if (yes==1) else 10
        tmp = 110 
        for i in range(2, yes):
            cnt += i*tmp
            tmp *= 10

        idx = (0 if (yes == 1) else mpow(10, yes-1)) + (n-cnt)//yes
        offset = 0
        if yes != 1:
            offset = (n-cnt) % yes
        buffer = f"{idx}"
        i = offset
        for x in buffer[offset:]:
            print(x, end='')
            i += 1
            k -= 1 
            if k == 0:
                break 

        while k != 0:
            for ii in range(i, len(buffer)):
                print(buffer[ii], end='')
                k -= 1 
                if k == 0:
                    break 

            i = 0 
            idx += 1 
            buffer = f"{idx}"
        print()

main()


