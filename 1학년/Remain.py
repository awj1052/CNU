a = input().split(" ")
N = int(a[0])
M = int(a[1])

num = input().split(" ")
for i in range(N):
    num[i] = int(num[i])

count = [0 for _ in range(M)]
for i in num:
    count[i%M]+=1

max = 0
max2 = 0
for i in count:
    if i > max:
        max2 = max
        max = i
    if i > max2 and max > i:
        max2 = i

arr = []
arr2 = []
for i in range(M):
    if count[i] == max:
        arr.append(i)
    elif count[i] == max2 and max2!=0:
        arr2.append(i)

print(max, end="개 : ")
for i in range(len(arr)-1):
    print(arr[i], end=", ")
print(arr[-1])

if max2 != 0:
    print(max2, end="개 : ")
    for i in range(len(arr2)-1):
        print(arr2[i], end=", ")
    print(arr2[-1])