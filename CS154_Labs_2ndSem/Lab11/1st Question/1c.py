count_table = {}

def updateCount (dic, key):
    if key in dic:
        dic[key] += 1
    else :
        dic[key] = 1




def ack(m,n): #defined only for non-negative inputs

    key = ""
    key = key + "(" + str(m) + "," + str(n) + ")"
    updateCount(count_table,key)


    if m == 0:
        return (n + 1)
    elif n == 0:
        return ack(m-1,1)
    else :
        return ack(m-1,ack(m,n-1))

#A few function calls are made to update the count_table
ack(0,0); ack(1,0); ack(0,1); ack(2,3)

print(count_table)
