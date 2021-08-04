lookup_table = {}



def ack(m,n): #defined only for non-negative inputs

    key = ""
    key = key + "(" + str(m) + "," + str(n) + ")"

    if key in lookup_table:
        retval = lookup_table[key]

    else:
        if m == 0:
            retval = (n + 1)
        elif n == 0:
            retval = ack(m-1,1)
        else :
            retval = ack(m-1,ack(m,n-1))

        lookup_table[key] = retval

    return retval

#A few function calls are made to update the lookup_table
ack(0,0); ack(1,0); ack(0,1); ack(2,3)

print(lookup_table)

#Finally, a large input is given to check the power of memoization

print(ack(3,4))
