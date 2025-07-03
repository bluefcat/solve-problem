n,t=map(int, input().split())
k,s=input().strip(),2**(n-t)
print(max(int(k[i:i+s])for i in range(0,2**n,s)))

