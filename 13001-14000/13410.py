n,k=map(int,input().split())
print(max(sorted(int(f'{n*x}'[::-1]) for x in range(1,k+1))))
