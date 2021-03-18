# Heaps

## 1. Binary Heaps

These are the heap structures, where a node is allowed to have a maximum of 2 child nodes.
These can be of two types, `min` and `max` heaps.

* A heap of size `n` has at most `n / (2 ^ (h + 1))`  nodes with height `h`

* The `Heapify` operation is used to assert the heap property. Its time complexity depends on the height of the tree `h` which is approximately `log(n)`.

* The `Build Heap` operation is used to build a heap from a completely randomly arranged numbers. So it runs a loop ranging from the last internal node (pos = `(heapsize/2)`) right up till the root node(pos = `0`). Its time complexity is `O(n)`.


## 2. Heapq Library

The `heapq` library is used to implement binary heaps with ease in `python`. This implements a `min-heap` by default. In the case for using this as a `max-heap`, we would have to negate the sign of the numbers while inserting them into the queue and also while extracting them from this class.
<br>
The functions available are : 

* heapify(iterable) : Converts the iterable data-structure into a heap
* heappush(heap, ele) : Inserts an element into the heap and corrects its property
* heappop(heap) : Return and remove the topmost element, and correct the heap property
* heappushpop(heap, ele) : Combines push and pop operations under one command
* heapreplace(heap, ele) : In this, element is first popped, then the element is pushed.i.e, the value larger than the pushed value can be returned.
* nlargest(k, iterable, key = fun) : Returns the `k` largest elements from the iterable specified and satisfying the key if mentioned.
* nsmallest(k, iterable, key = fun) : Returns the `k` smallest elements from the iterable specified and satisfying the key if mentioned.
