def sub (List1, List2):
        
    l1 = len(List1)
    l2 = len(List2)
    if not l1:
        return [True];
    elif l1 > l2:
        return [False];
    else : 
                
        index = 0
        for i in range(0, l2):
            if List1[0] == List2[i]:
                break
            index += 1
        
        if index == l2:
            return [False];
        
        elif List2[index: index + l1] == List1:
            return [True];
        else:
            return sub(List1, List2[index + l1 -1:]); #THE RECURSIVE PART

print(sub([1,2], [1,2,3,4]))
print(sub([1,3,2], [1,2,3,4]))
