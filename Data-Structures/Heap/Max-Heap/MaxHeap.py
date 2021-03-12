def max_heapify(arr, i) :
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
        heapify(arr, n, largest)

s = input()
s = s.split(' ')
arr = [int(i) for i in s]
n = len(arr)
for i in range(n, -1, -1) :
    max_heapify(arr, i)
print(arr)
