import sys
input = sys.stdin.readline
MOD = 1_234_543

fact = [1]
for i in range(1, MOD + 1):
    fact.append(fact[-1] * i % MOD)


def comb(N, K, M):
    lucas = []
    while N > 0 and K > 0:
        lucas.append((N % M, K % M))
        N //= M
        K //= M

    ret = 1
    for n, k in lucas:
        if 0 <= k <= n:
            ret = ret * fact[n] * pow(fact[n - k], -1, M) * pow(fact[k], -1, M) % M
        else:
            ret = 0
            break
    return ret


for _ in range(int(input())):
    W, B = map(int, input().split())
    print('even' if B & 1 == 0 else 'odd', comb(W + B - 1, B, MOD))

