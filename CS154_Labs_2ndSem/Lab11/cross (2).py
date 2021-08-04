retval = []
def cross(l1, l2):
    if len(l2) == 0:
        return retval
    else:
        for x in l1:
            retval.append([x,l2[0]])
        return cross(l1, l2[1:])

print(cross([1,2,3,4,5],['a','v','h']))
