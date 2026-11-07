keys = ["h", "d", "e", "l", "o", "r", "w"]
data = {key: 0 for key in keys}

def get_number(d: dict, *arr):
    result = 0
    for x in arr:
        result *= 10
        result += d[x]
    return result

def check(d: dict, N: int):
    return (get_number(d, *"hello") + get_number(d, *"world")) == N


def printf(d, N):
    x, y = get_number(d, *"hello"), get_number(d, *"world")
    print(f"{x:>7}")
    print(f"+{y:>6}")
    print(f"-------")
    print(f"{N:>7}")


N = int(input())


for x in range(10**6, 10**7):
    word = f"{x}"
    if  word[-1] == '0' or len(set(word)) != 7:
        continue
    for k, v in zip(data, word):
        data[k] = int(v)
    
    if check(data, N):
        printf(data, N)
        break

else:
    print("No Answer")
