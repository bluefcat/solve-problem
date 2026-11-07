import sys
from collections import Counter
input = sys.stdin.readlines
print(sum([v >= 3 for v in Counter([i.strip() for i in input()]).values()]))