f=[i for i in range(16)]
f[0] = 1
for i,_ in enumerate(f[1:]):
    f[i+1] *= f[i]

n,a,b,c=map(int,input().split())

print(f[n]//(f[n-a-b]*f[a]*f[b]))
