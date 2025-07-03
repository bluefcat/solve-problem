_, k = map(int, input().split())
arr = [*map(int, input().split())]
result = -1

def merge(a, p, q, r):
    global k, result
    i,j= p, q+1
    tmp = []
    while i <= q and j <= r:
        if a[i] <= a[j]:
            tmp.append(a[i]);i+=1 
        else:
            tmp.append(a[j]);j+=1
    while i <= q:
        tmp.append(a[i]);i+=1 
    while j <= r:
        tmp.append(a[j]);j+=1
    for t, e in enumerate(tmp):
        k -= 1
        if k == 0:
            result = e
        a[p+t] = e 

def merge_sort(a, p, r):
    if p >= r: return 
    q = (p + r) >> 1
    merge_sort(a, p, q)
    merge_sort(a, q+1, r)
    merge(a, p, q, r)
merge_sort(arr, 0, len(arr)-1)
print(result)
