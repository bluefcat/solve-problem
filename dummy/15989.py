cache = [0 for _ in range(10001)]
cache[0] = 1
cache[1] = 1
cache[2] = 2
cache[3] = 3
cache[4] = 4

T = int(input())
for i in range(10000+1)[5:]:
        #
        # d[i] = d[i-1] + (d[i-2] - d[i-3]) + (i % 3 == 0 and 1 or 0)
        # (d[i-2] - d[i-3]) 은 d[i-2]의 중복 제거
        # 3 + 3 + 3 에 대한 처리 i % 3 == 0 으로 처리
        #
        cache[i] = cache[i-1] + (cache[i-2] - cache[i-3])
        if i % 3 == 0:
            cache[i] += 1

for _ in range(T):
    n = int(input())

    print(f"{cache[n]}")