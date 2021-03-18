"""
This Program utilizes the `heapq` library of python to implement a Min-Heap.

The `heapq` library implements a min-heap by default.
"""

import heapq


class MinHeap :

    def __init__(self, arr = []) :
        """
        Initializes the iterable, and forms a heap.
        """
        self.heap = arr
        heapq.heapify(self.heap)
    
    def insert(self, ele) :
        """
        Inserts an element into the min-heap.
        """
        heapq.heappush(self.heap, ele)
    
    def extractMinElement(self) :
        """
        Removes and returns the minimum(root) element from the heap.
        """
        return heapq.heappop(self.heap)


# Runner code

heapObj = MinHeap()
heapObj.insert(3)
heapObj.insert(2)
heapObj.insert(15)
heapObj.insert(5)
heapObj.insert(4)
heapObj.insert(45) 
print(heapObj.extractMinElement())
print(heapObj.extractMinElement())
print(heapObj.extractMinElement())
