#print(list(range(5)))
'''
def fun(input):
    if(len(input)):
        return (fun(input[1:])) + [input[0]]
    return []

input = [1,2,3,4,5]

print(input[2::-1])
'''
s1 = {1,2,3,4,5}
s2 = {2,3,6,7,8}
print(s1&s2)
print(s1-s2)
print(s1|s2)
