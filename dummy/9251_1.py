a,b=input(),input()
m={}
def c(i,j):
 if i>=len(a):return 0
 for j in range(j,len(b)):
  if b[j]==a[i]:
   k=(i,j)
   if k not in m:
    m[k]=1
    for i in range(i,len(a)):m[k]=max(c(i+1,j+1)+1,m[k])
   return m[k]
 return 0
print(max([c(i,0)for i in range(len(a))]))