x, k = map(int, input().split())
xb, kb = map(lambda t: bin(t)[2:], [x, k])
y = ''

kidx = len(kb)-1
for i in xb[::-1]:
    if i == '0':
        if kidx >= 0:
            y = kb[kidx] + y
            kidx -= 1
        else:
            y = '0' + y
    else:
        y = '0' + y
y = kb[:kidx+1] + y
y = int(y, 2)
print(y)
