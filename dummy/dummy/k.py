"""
hello
"""
from itertools import product
from tqdm import tqdm
from random import randint
def h(x, y):
    """
    hashing
    """
    db = [29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79]
    for p in db:
        q, r, s = 1, 0, 0
        for xx in x:
            r = (r + q * ord(xx)) % 1000000007
            q = p*q % 1000000007

        q = 1
        for yy in y:
            s = (s + q * ord(yy)) % 1000000007
            q = p*q % 1000000007

        return r == s
    return False

def get_string(n = 1):
    """
    make random string
    """
    comb = "abcdefghijklmnopqrstuvwxyz"
    return "".join([comb[randint(0, 25)] for _ in range(n)])

def main():
    """
    main entry
    """
    for l in tqdm(range(1, 300001)):
        for _ in range(1, 1000):
            a, b = get_string(l), get_string(l)
            if a != b and h(a, b):
                print(a, b)
                return
    return

if __name__ == "__main__":
    main()
