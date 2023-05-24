n, m = map(int, input().split())
dex = {str(i+1): input() for i in range(n)}
dex.update(**{v: k for k, v in dex.items()})
[print(dex[input()]) for _ in range(m)]
