import random, sys
sys.setrecursionlimit(10**4)

import mytimer
    
@mytimer.mytimer
def quickselect_random(arr, k):
    global call
    call = 0
    return __quickselect_random(arr, k, 0)


@mytimer.mytimer
def quickselect_random_good(arr, k):
    global call, choose
    call = 0
    choose = 0
    return __quickselect_random(arr, k, 1)

call = 0
choose = 0
def __quickselect_random(arr, k, f):
    global choose, call
    call += 1
    idx = 0
    if f:
        choose += 1
        while not is_good_pivot(arr, arr[idx]):
            choose += 1
            idx = random_index(arr)

    pivot = arr[idx]
    small, big = partitioning(arr, pivot)
    if len(small) == k-1:
        return pivot
    if len(small) >= k:
        return __quickselect_random(small, k, f)
    return __quickselect_random(big, k - (len(small)+1), f)


def random_index(arr):
    return random.randint(0, len(arr)-1)


def partitioning(arr, pivot):
    small = []
    big = []
    for e in arr:
        if e > pivot:
            big.append(e)
        elif e < pivot:
            small.append(e)
    return small, big


def is_good_pivot(arr, pivot):
    n = len(arr)
    small, big = partitioning(arr, pivot)
    if n//4 <= len(small) <= (3*n//4):
        return True
    return False