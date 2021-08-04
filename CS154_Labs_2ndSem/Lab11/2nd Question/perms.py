retval = []

def permutations(List, n):
    
    l = len(List)
    if n == l - 1:
        retval.append(tuple(List))
        
    for i in range(n, l):
        List[i], List[n] = List[n], List[i] 
        permutations(List, n + 1)
        List[i], List[n] = List[n], List[i] 
    
    return list(set(retval)) #set removes any identical permutations in case there are identical elements in our list


print(permutations([1,2,3,4],0))

