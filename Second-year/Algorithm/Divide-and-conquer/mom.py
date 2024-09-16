import sys
sys.setrecursionlimit(10**4)

import mytimer

@mytimer.mytimer
def quickselect_mom5(arr, k):
    global call
    call = 0
    return __quickselect_mom(arr, k, 5)


@mytimer.mytimer
def quickselect_mom11(arr, k):
    global call
    call = 0
    return __quickselect_mom(arr, k, 11)


@mytimer.mytimer
def quickselect_mom15(arr, k):
    global call
    call = 0
    return __quickselect_mom(arr, k, 15)

@mytimer.mytimer
def quickselect_mom101(arr, k):
    global call
    call = 0
    return __quickselect_mom(arr, k, 101)

call = 0
def __quickselect_mom(arr, k, size):
    global call
    call += 1
    n = len(arr)
    if n <= size**2:
        sorted_arr = sorted(arr)
        return sorted_arr[k-1]
    
    m = []
    for i in range((n+size-1)//size):
        median = get_median(arr[size*i:min(size*i+size, n)])
        m.append(median)
    mom = __quickselect_mom(m, (len(m)+1)//2, size)

    small, big = partitioning(arr, mom)
    if len(small) == k-1:
        return mom
    if len(small) >= k:
        return __quickselect_mom(small, k, size)
    return __quickselect_mom(big, k - (len(small)+1), size)


def get_median(arr):
    sorted_arr = sorted(arr)
    return sorted_arr[len(sorted_arr)//2]


def partitioning(arr, pivot):
    small = []
    big = []
    for e in arr:
        if e > pivot:
            big.append(e)
        elif e < pivot:
            small.append(e)
    return small, big