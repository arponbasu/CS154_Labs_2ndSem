import time

lookup_table = {}

def Fibonacci(n): #defined only for non-negative inputs


    if n == 0:
        return 1
    elif n == 1:
        return 1
    else:
        return (Fibonacci(n-1) + Fibonacci(n-2))



def Fibonacci_Memoized(n): #defined only for non-negative inputs

    key = str(n)

    if key in lookup_table:
        retval = lookup_table[key]

    else:
        if n == 0:
            retval = 1
        elif n == 1:
            retval = 1
        else:
            return (Fibonacci_Memoized(n-1) + Fibonacci_Memoized(n-2))
        lookup_table[key] = retval

    return retval

input = 10

start = time.time()
print(Fibonacci(input))
end = time.time()
val1 = end - start
#print("Time taken by ordinary Fibonacci function is ", val1)

start = time.time()
print(Fibonacci_Memoized(input))
end = time.time()
val2 = end - start
#print("Time taken by memoized Fibonacci function is ", val2)

val = val1/val2
print("For input = ", input, "the mem_Fibonacci function runs ", val, "times faster than the ordinary one.")
