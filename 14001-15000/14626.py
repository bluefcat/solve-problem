n=input()
x=[[*map(lambda x: k if x=='*' else int(x), n)] for k in range(10)]
for i, e in enumerate(x):
    if sum(((j%2)==0)*w+3*(j%2)*w for j, w in enumerate(e)) % 10 == 0:
        print(i)
        exit(0)
