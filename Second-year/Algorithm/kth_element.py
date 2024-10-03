import random

upper = 50
arr = [i for i in range(1,upper+1)]
random.shuffle(arr)

partition = random.randint(1, len(arr))
x = arr[:partition]
y = arr[partition:]
x.sort()
y.sort()
k = random.randint(1,upper)
print(k)

def find_k(n, m, k):
    if len(n) == 0:
        return m[k-1]
    if len(m) == 0:
        return n[k-1]
    
    arr1, arr2 = n, m
    a = (len(arr1)-1)//2
    b = (len(arr2)-1)//2
    if arr1[a] > arr2[b]:
        arr1, arr2 = arr2, arr1
        a, b = b, a
    
    # if k < a+1:
    #     return find_k(arr1[:a], arr2[:b], k)
    if k < a+b+2:
        return find_k(arr1, arr2[:b], k)
    return find_k(arr1[a+1:], arr2, k - (a+1))

print(find_k(x, y, k))