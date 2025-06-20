from math import gcd

class Field:
    def __init__(self, a, b, c, d):
        x = gcd(a, b, c)
        if a < 0:
            a, b, c = -a, -b, -c
        if c == 0 or d == 0:
            c, d = 0, 0
        self.a, self.b, self.c, self.d = a//x, b//x, c//x, d  

    def __add__(self, other):
        return Field(
                self.a*other.a, 
                self.b*other.a+self.a*other.b,
                self.c*other.a+self.a*other.c,
                self.d 
        )

    def __sub__(self, other):
        return Field(
                self.a*other.a, 
                self.b*other.a-self.a*other.b,
                self.c*other.a-self.a*other.c,
                self.d 
        )
    
    def __mul__(self, other):
        return Field(
                self.a*other.a, 
                self.b*other.b + self.c*other.c*self.d,
                self.b*other.c + self.c*other.b,
                self.d 
        )
    def __truediv__(self, other):
        return self * Field(
            other.b**2 - other.c**2 * other.d,
            other.a * other.b,
            -other.a * other.c,
            other.d
        )

    def __repr__(self):
        return f"{self.a} {self.b} {self.c} {self.d}"

a=Field(*map(int,input().split()))
b=Field(*map(int,input().split()))
print(a+b, a-b, a*b, a/b, sep="\n")
