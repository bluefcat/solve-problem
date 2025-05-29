x = [*map(lambda x: f"{bin(int(x))[2:]:0>4}"[-4:], open(0))]
print(f"{int(''.join(x),2):0>4}")
