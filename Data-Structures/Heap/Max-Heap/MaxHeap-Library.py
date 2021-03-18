"""
This Program utilizes the `heapq` library of python to implement a Min-Heap.

As the `heapq` library implements a min-heap by default, we negate every element while inserting and removing to and from the heap.
"""

import heapq


class MaxHeap :

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
        heapq.heappush(self.heap, (-1 * ele))
    
    def extractMaxElement(self) :
        """
        Removes and returns the minimum(root) element from the heap.
        """
        return (-1 * heapq.heappop(self.heap))


# Runner code

heapObj = MaxHeap()
heapObj.insert(3)
heapObj.insert(2)
heapObj.insert(15)
heapObj.insert(5)
heapObj.insert(4)
heapObj.insert(45) 
print(heapObj.extractMaxElement())
print(heapObj.extractMaxElement())
print(heapObj.extractMaxElement())
