#%%

# Version 1 :


def heapify(arr, n, i) :
    l = 2*i + 1
    r = 2*i + 2
    largest = i
    
    if l<n and arr[largest]<arr[l] :
        largest = l
    if r<n and arr[largest]<arr[r] :
        largest = r
    
    if largest!=i :
        arr[largest], arr[i] = arr[i], arr[largest]
        heapify(arr, n, largest)


def heap_sort(arr) :
    n = len(arr)
    
    for i in range(n, -1, -1) :
        heapify(arr, n, i)
    
    for i in range(n-1, 0, -1) :
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
        
s = input()
s = s.split(' ')
arr = [int(i) for i in s]
heap_sort(arr)
print(arr)



#%%

# Version 2


def heapify(arr, i) :
    n = len(arr)
    l = 2*i + 1
    r = 2*i + 2
    largest = i
    
    if l<n and arr[largest]<arr[l] :
        largest = l
    if r<n and arr[largest]<arr[r] :
        largest = r
    
    if largest!=i :
        arr[largest], arr[i] = arr[i], arr[largest]
        heapify(arr, largest)


def heap_sort(arr) :
    n = len(arr)
    
    for i in range(n, -1, -1) :
        heapify(arr, i)
    
    arr1 = arr[:]
    arr = []
    
    for i in range(n-1, 0, -1) :
        arr1[0], arr1[i] = arr1[i], arr1[0]
        arr.append(arr1[i])
        arr1 = arr1[:i]
        heapify(arr1, 0)
    
    arr = arr + arr1
    arr.reverse()
    return(arr)
        
s = input()
s = s.split(' ')
arr = [int(i) for i in s]
arr = heap_sort(arr)
print(arr)
