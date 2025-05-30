import sys 
input = sys.stdin.readline

_ = input()
arr = sorted([*map(int, input().split())])
print(arr[((len(arr)+(len(arr)&1))>>1)-1])
