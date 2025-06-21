#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Heap implementation
// STL priority_queue is a max-heap by default

class MaxHeap {
public:
  void push(int value) {
    heap.push_back(value);
    // STL has: push_heap(heap.begin(), heap.end());
    // but let's implement it outselves for educational purposes
    // Bubble up the new element to maintain the heap property
    int index = heap.size() - 1;
    while (index > 0) {
      int parentIndex = (index - 1) / 2;
      if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
      } else {
        break; // The heap property is satisfied
      }
    }
  }

  int top() {
    if (heap.empty()) {
      throw runtime_error("Heap is empty");
    }
    return heap.front(); // Return the maximum element (the root)
  }

  void pop() {
    if (heap.empty()) {
      throw runtime_error("Heap is empty");
    }
    // STL has: pop_heap(heap.begin(), heap.end());
    // but let's implement it ourselves for educational purposes
    // Trickle down the root element to maintain the heap property
    swap(heap.front(), heap.back());
    // Remove the last element (the max value)
    heap.pop_back();
    if (heap.empty()) {
      return; // The heap is now empty
    }
    // Now we need to bubble down the new root element
    int index = 0;
    while (true) {
      int leftChildIndex = 2 * index + 1;
      int rightChildIndex = 2 * index + 2;
      int largestIndex = index;

      if (leftChildIndex < heap.size() &&
          heap[leftChildIndex] > heap[largestIndex]) {
        largestIndex = leftChildIndex;
      }
      if (rightChildIndex < heap.size() &&
          heap[rightChildIndex] > heap[largestIndex]) {
        largestIndex = rightChildIndex;
      }
      if (largestIndex == index) {
        break; // The heap property is satisfied
      }
      swap(heap[index], heap[largestIndex]);
      index = largestIndex;
    }
  }

  bool isEmpty() const { return heap.empty(); }

private:
  vector<int> heap; // Internal storage for the heap
};
// Example usage of the MaxHeap class
void testHeap() {
  MaxHeap maxHeap;
  maxHeap.push(10);
  maxHeap.push(20);
  maxHeap.push(5);
  maxHeap.push(30);

  cout << "Max Heap: ";

  while (!maxHeap.isEmpty()) {
    cout << "Top value is: " << maxHeap.top() << endl;
    maxHeap.pop();
  }
}
// Main function to run the heap test
int main() {
  cout << "Starting heap test..." << endl;
  testHeap();
  cout << "Heap test completed successfully." << endl;
  return 0;
}
