import sys 
input = sys.stdin.readline 

x = [*open(0)][:-1]
n,c = x[0].split();c=int(c)
cur,s = map(int, x[1:3]) 
for l in filter(x[3:], func=lambda x: map(int, x.split())):
    cur = max(0, cur-l)
    cur = min(c, cur+b)
print(n, cur)
