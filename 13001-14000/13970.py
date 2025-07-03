import sys;input=sys.stdin.readline 

LIMIT: int = 1_000_007
class phi:
    def __new__(cls, x):
        if not hasattr(cls, "_instance"):
            cls._instance = super(phi, cls).__new__(cls)
            cls._instance._phi = [x for x in range(LIMIT)]
            for i, _ in enumerate(cls._instance._phi):
                if i == 0:
                    continue
                for j in range(i+i, LIMIT, i):
                    cls._instance._phi[j] -= cls._instance._phi[i]
        return cls._instance(x)

    def __call__(self, x: int): 
        return self._phi[x]


def tower(arr, i, m):
    if m == 1:
        return 1
    if i == len(arr)-1:
        return arr[i]

    x = arr[i]
    e = tower(arr, i+1, phi(m))

    if e < phi(m):
        return pow(x, e)
    return pow(x, e % phi(m) + phi(m))

phi(0)
t, m = map(int, input().split())
for _ in range(t):
    x, *arr = map(int, input().split())
    e = 1
    print(tower(arr, 0, m) % m)

