from math import gcd

class Field:
    def __init__(self, a, b, c, d):
        x = gcd(a, b, c)
        if a < 0:
            a, b, c = -a, -b, -c
        if c == 0 or d == 0:
            c, d = 0, 0
        self.a, self.b, self.c, self.d = a//x, b//x, c//x, d  

    def __neg__(self):
        return Field(self.a, -self.b, -self.c, self.d)

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

class Complex:
    def __init__(self, a, b):
        self.a, self.b = a, b

    def __add__(self, other):
        return Complex(self.a+other.a, self.b+other.b)

    def __sub__(self, other):
        return Complex(self.a-other.a, self.b-other.b)
    
    def __mul__(self, other):
        a,b,c,d=self.a,self.b,other.a,other.b
        return Complex(a*c-b*d, a*d+b*c)

    def __truediv__(self, other):
        a,b=other.a,other.b
        m=a*a+b*b
        return self * Complex(a/m, -b/m)
    
    def __repr__(self):
        return F"{self.a} {self.b}"

k=[*map(int,input().split())]
a=Complex(Field(*k[:4]), Field(*k[4:]))
k=[*map(int,input().split())]
b=Complex(Field(*k[:4]), Field(*k[4:]))
print(a+b, a-b, a*b, a/b, sep="\n")

