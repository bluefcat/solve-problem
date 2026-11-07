N, K = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
counter = [0 for _ in range(11)]

for _, i in arr:
    counter[i] += 1


tmp = sorted([(i, v[0] + counter[v[1]] - 1, v[1]) for i, v in enumerate(arr)], key=lambda x: -counter[x[2]])
tmp = sorted(tmp, key=lambda x: -x[1])


print(tmp[:K])

#[13 2, 14 2, 16 3, 11 2]