def quickSort(arr, left, right):
    if left<right:
        pivot = partition(arr, left, right)
        quickSort(arr, left, pivot-1)
        quickSort(arr, pivot+1, right)
        
def partition(arr,left,right):
    pivot_index = right
    arr_index = left
    for i in range(left,right):
        if arr[i] < arr[pivot_index]:
            arr[i],arr[arr_index] = arr[arr_index],arr[i]
            arr_index+=1
    arr[arr_index],arr[pivot_index] = arr[pivot_index], arr[arr_index]
    return arr_index
        