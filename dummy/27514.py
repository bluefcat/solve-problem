"""
a
"""
from collections import Counter

_ = input()
array = list(map(int, input().split()))
counter = Counter([x for x in array if x != 0])

if counter:
    key = min(counter)

    updater = key
    while any([k >= 2 for _, k in counter.most_common()]):
        counter[updater*2] += counter[updater] // 2
        counter[updater] %= 2
        updater *= 2

    print(max(counter))
else:
    print(0)