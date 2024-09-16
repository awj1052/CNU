import random
import sorting, random_pivot, mom

arr = [i for i in range(1,10**6)]
k = 11

random.shuffle(arr)

sorting.quickselect_sort(arr, k)
print()
random_pivot.quickselect_random(arr, k)
print(f'\tfunction calls: {random_pivot.call}')
random_pivot.quickselect_random_good(arr, k)
print(f'\tfunction calls: {random_pivot.call}\tpivot average: {random_pivot.choose / random_pivot.call:.2f}')
mom.quickselect_mom5(arr, k)
print(f'\tfunction calls: {mom.call}')
mom.quickselect_mom11(arr, k)
print(f'\tfunction calls: {mom.call}')
mom.quickselect_mom15(arr, k)
print(f'\tfunction calls: {mom.call}')
mom.quickselect_mom101(arr, k)
print(f'\tfunction calls: {mom.call}')