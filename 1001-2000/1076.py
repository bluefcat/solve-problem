import sys

input = sys.stdin.readline

x = input().strip()
y = input().strip()
z = input().strip()

d = [
    "black", "brown", "red", "orange", "yellow",
    "green", "blue", "violet", "grey", "white"
]

print((d.index(x)*10 + d.index(y)) * (10**d.index(z)))
