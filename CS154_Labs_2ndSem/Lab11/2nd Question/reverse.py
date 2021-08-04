def reverse (l, n): # n <= len(l); reverses first n elements of the list l
    if n == 0:
        return []
    else:
        return [l[n - 1]] + reverse(l[:n - 1], n - 1) + l[n:]

print(reverse([1,2,3,4,5,6,7,8,9],9))
print(reverse([1,2,3,4,5,6,7,8,9],5))
