def min_heapify(arr, i) :
    n = len(arr)
    l = 2*i + 1
    r = 2*i + 2
    smallest = i
    
    if l<n and arr[smallest]>arr[l] :
        smallest = l
    if r<n and arr[smallest]>arr[r] :
        smallest = r
    
    if smallest!=i :
        arr[smallest], arr[i] = arr[i], arr[smallest]
        heapify(arr, n, smallest)

s = input()
s = s.split(' ')
arr = [int(i) for i in s]
n = len(arr)
for i in range(n, -1, -1) :
    min_heapify(arr, i)
print(arr)
