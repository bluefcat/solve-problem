import sys

N = 1_000_000_1
# N = 1_000_000_001
prime = [True for _ in range(N)]

def init():
    prime[0] = False
    prime[1] = False
    prime[2] = True
    for i in range(2, N, 2):
        prime[i] = False
    
    for i in range(3, N, 2):
        if not prime[i]:
            continue

        for j in range(2, N):
            if i * j >= N:
                break
            prime[i*j] = False

init()
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = input().strip()

    if n[-1] == '5':
        print("0 5")
        continue
    
    s = 0
    co = 0
    cf = 0
    for nx in n:
        s += int(nx)
        co += (nx == '1')
        cf += (nx == '5')

    if s % 3 == 0:
        print("0 3")
        continue

    if co >= 1 and (s-1) %3 == 0:
        idx = n.find("1") + 1
        print(f"{idx} 3")
        continue

    if cf >= 1 and (s-5) %3 == 0:
        idx = n.find("5") + 1
        print(f"{idx} 3")
        continue 

    sq = s- 2*int(n[-1])
    if sq % 7 == 0:
        print("0 7")

    if co >= 1 and (sq-1) %7 == 0:
        idx = n.find("1") + 1
        print(f"{idx} 7")
        continue

    if cf >= 1 and (sq-5) %7 == 0:
        idx = n.find("5") + 1
        print(f"{idx} 7")
        continue 
    
    sq = s + 3*int(n[-1])
    if sq % 13 == 0:
        print("0 13")

    if co >= 1 and (sq-1) %13 == 0:
        idx = n.find("1") + 1
        print(f"{idx} 13")
        continue

    if cf >= 1 and (sq-5) %13 == 0:
        idx = n.find("5") + 1
        print(f"{idx} 13")
        continue 

    sq = s - 6*int(n[-1])
    if sq % 17 == 0:
        print("0 17")

    if co >= 1 and (sq-1) %17 == 0:
        idx = n.find("1") + 1
        print(f"{idx} 17")
        continue

    if cf >= 1 and (sq-5) %17 == 0:
        idx = n.find("5") + 1
        print(f"{idx} 17")
        continue 

    sq = s + 1*int(n[-1])
    if sq % 19 == 0:
        print("0 19")

    if co >= 1 and (sq-1) %19 == 0:
        idx = n.find("1") + 1
        print(f"{idx} 19")
        continue

    if cf >= 1 and (sq-1) %19 == 0:
        idx = n.find("5") + 1
        print(f"{idx} 19")
        continue 
