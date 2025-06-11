import sys 
input=sys.stdin.readline 
n,t=input().split()
k={"Y":1,"F":2,"O":3}
s=set(input().strip()for _ in range(int(n)))
print(len(s)//k[t])
