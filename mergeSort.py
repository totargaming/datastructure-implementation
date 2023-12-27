from collections import deque
def mergeSort(arr: list, left: int, right: int):
    middle = 0
    if left < right:
        middle = (left+right)//2
        mergeSort(arr, left, middle)
        mergeSort(arr, middle +1, right)
        
        merge(arr, left, middle, right)
        
        
def merge(arr, left, middle, right):
    i =0
    buffer1 = buffer2 = deque()
    
    for i in range(middle+1): buffer1.append(arr[i])
    for i in range(middle+1,right): buffer2.append(arr[i])
    
    i = left
    while buffer1 and buffer2:
        if buffer1[0]< buffer2[0]:
            arr[i] = buffer1.popleft()
            
        else:
            arr[i] = buffer2.popleft()
            
        i+=1
        
    while buffer1:
        arr[i] = buffer1.popleft()
        i+=1
    while buffer1:
        arr[i] = buffer2.popleft()
        i+=1
        
    