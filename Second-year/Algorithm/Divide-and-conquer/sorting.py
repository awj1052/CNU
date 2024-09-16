import mytimer

@mytimer.mytimer
def quickselect_sort(arr, k):
    sorted_arr = sorted(arr)
    return sorted_arr[k-1]
