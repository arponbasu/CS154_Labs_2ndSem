def ack(m,n): #defined only for non-negative inputs
    if m == 0:
        return (n + 1)
    elif n == 0:
        return ack(m-1,1)
    else :
        return ack(m-1,ack(m,n-1))
