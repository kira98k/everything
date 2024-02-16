def f(x):
    # count number of bits set to 0
    if x == 1: return 0
    if x % 2 == 0:  return f(x//2)+1
    return f(x//2)

def g(x):
    # flip all bits except the highest set bit
    if x == 1: return 1
    if x % 2 == 0:  return 2*g(x//2)+1
    return 2*g(x//2)


for i in range(1, 300):
    print(f"{i} : {bin(i)[2:]} : {f(i)} + {g(i)} = {f(i)+g(i)}")

