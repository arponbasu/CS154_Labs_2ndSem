def ack(m,n): #defined only for non-negative inputs

    ack.counter += 1

    if m == 0:
        return (n + 1)
    elif n == 0:
        return ack(m-1,1)
    else :
        return ack(m-1,ack(m,n-1))

ack.counter = 0

print(ack(0,0), end = '\t')
print(ack.counter)
print("==============================")

print(ack(1,0), end = '\t')
print(ack.counter)
print("==============================")

print(ack(0,1), end = '\t')
print(ack.counter)
print("==============================")

print(ack(2,3), end = '\t')
print(ack.counter)
print("==============================")

print(ack(3,4), end = '\t')
print(ack.counter)
print("==============================")

print(ack(4,5), end = '\t')
print(ack.counter)
print("==============================")
