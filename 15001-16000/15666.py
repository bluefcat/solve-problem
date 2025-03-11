def product(*iterables, repeat=1):
    pools = [tuple(pool) for pool in iterables] * repeat
    result = [[]]

    for pool in pools:
        result = [
            x + [y] for x in result for y in pool if (x == []) or (x and x[-1] <= y)
        ]

    for prod in result:
        yield tuple(prod)


m, n = map(int, input().split())
l = set(map(int, input().split()))
l = sorted(list(l))

for i in product(l, repeat=n):
    print(' '.join(map(str, i)))
