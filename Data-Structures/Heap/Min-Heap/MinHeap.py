#%%

# Version 2

class MinHeap :

    def __init__(self, capacity = 100, arr = []) :
        """
        Initializes the Heap.
        """

        self.heap = arr
        self.heap_size = len(self.heap)
        self.buildMinHeap()
        self.capacity = capacity
    
    def left(self, pos) :
        """
        Returns the position of the left child to the current node.
        """
        return (2 * pos) + 1
    
    def right(self, pos) :
        """
        Returns the position of the right child to the current node.
        """
        return (2 * pos) + 2
    
    def parent(self, pos) :
        """
        Returns the position of the parent to the current node.
        """
        return (pos - 1) // 2

    def buildMinHeap(self) :
        """
        This function builds a min-heap out of a un-sorted array of numbers.
        This is a bottom - up approach.
        """

        if self.heap_size <= 0 :
            return

        # This finds the Min Heap
        inner_limit = self.heap_size // 2
        # We run the Min Heapify operation for all the inner nodes of the heap
        for i in range(inner_limit, -1, -1) :
            self.minHeapify(i)
    
    def fixMinHeap(self, pos) :
        """
        This function is similar to the `buildMinHeap`, the only difference being that it 
        does not cover the whole heap, but instead works its way up from a particular position.

        It is also a Bottom-up approach.

        Parameters :
        pos -- The index from where this operation needs to be applied.

        Raises exception if heap size is less than the entered position.
        """

        if self.heap_size <= pos :
            raise IndexError
        
        # Goes up the chain until the heap property is restored
        while (pos > 0) and (self.heap[self.parent(pos)] > self.heap[pos]) :
            self.heap[self.parent(pos)], self.heap[pos] = self.heap[pos], self.heap[self.parent(pos)]
            pos = self.parent(pos)
    
    def minHeapify(self, pos) :
        """
        Performs Min-Heapify operation from the node whose position is entered.
        This is a top-down approach.

        Parameters :
        pos -- The index where this operation needs to be applied.

        Raises exception if heap size is less than the entered position.
        """

        if self.heap_size <= pos :
            raise IndexError

        l = self.left(pos)
        r = self.right(pos)
        smallest = pos

        if (l < self.heap_size) and (self.heap[smallest] > self.heap[l]) :
            smallest = l
        if (r < self.heap_size) and (self.heap[smallest] > self.heap[r]) :
            smallest = r
        
        if smallest != pos :
            self.heap[smallest], self.heap[pos] = self.heap[pos], self.heap[smallest]
            self.minHeapify(smallest)
    
    def getMinElement(self) :
        """
        Returns the Minimum Element from the Min-Heap.

        Raises exception if heap is empty.
        """

        if self.heap_size <= 0 :
            raise IndexError
        
        return self.heap[0]

    def extractMinElement(self) :
        """
        Deletes the Minimum Element from the heap and returns it.

        Return :
        ele -- The minimum element that was removed from the heap

        Raises exception if the heap is empty.
        """

        if self.heap_size <= 0 :
            raise IndexError

        # If we have a heap of size 1, we remove the element and return it.
        if self.heap_size == 1 :
            ele = self.heap[0]
            self.heap.pop()
            self.heap_size -= 1
            return ele

        # Extract the minimum element
        ele = self.heap[0]
        # Replace the top of the heap by the last element
        self.heap[0] = self.heap[self.heap_size - 1]
        # Remove off the last element from the heap and reduce its size
        self.heap.pop(self.heap_size - 1)
        self.heap_size -= 1

        # As we have many other elements in the heap, the min-heap property is violated.
        self.minHeapify(0)

        # We return the minimum value
        return ele
    
    def insert(self, ele) :
        """
        Given an element, we insert it in the correct location in the heap.

        Parameters :
        ele -- The element to be inserted
        """

        # Check if the heap is not full
        if self.heap_size == self.capacity :
            raise Exception("The Heap is already Full")

        # Append the element to the end of the heap
        self.heap.append(ele)
        self.heap_size += 1

        # Fix the Min-heap Property if it is violated
        pos = self.heap_size - 1
        self.fixMinHeap(pos)
    
    def delete(self, pos) :
        """
        Given the position of an element, deletes it from the heap.

        Parameters :
        pos -- The position of the element to be deleted 1-indexed

        Return :
        ele -- The value of the deleted element

        Raises exception if the entered position is greated than the current heap size
        """

        # Reduce pos because it starts with 1
        pos -= 1

        if self.heap_size <= pos :
            raise IndexError

        # Replace the value of the element in pos to a very low value
        self.heap[pos] = -1 * float("inf")

        # Fix the violated heap property
        # This will bring the node to the top of the heap
        self.fixMinHeap(pos)

        # Delete the top element from the heap
        return self.extractMinElement()


# Runner code

heapObj = MinHeap() 
heapObj.insert(3)
heapObj.insert(2)
heapObj.delete(1)
heapObj.insert(15) 
heapObj.insert(5) 
heapObj.insert(4) 
heapObj.insert(45) 
print (heapObj.extractMinElement())
print (heapObj.extractMinElement())
print (heapObj.extractMinElement())


#%%

# Version 1

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
