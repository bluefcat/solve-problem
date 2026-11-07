while True:
    n = input()
    l = set()

    if n == "0":
        break
    
    l.add(n)
    n = f"{str(int(n) ** 2):0>8}"[2:6]

    while n not in l:
        l.add(n)
        n = f"{str(int(n) ** 2):0>8}"[2:6]

    print(len(l))
