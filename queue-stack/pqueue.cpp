#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

void defaultPQ() {
  // Using std::priority_queue
  cout << "* Default priority queue using std::priority_queue" << endl;
  // How is PQ implemented? Usually a max-heap is used, a binary tree where
  // the parent node is greater than or equal to its child nodes.
  // The top element is always the largest element in the queue.
  priority_queue<int> pq;
  pq.push(30);
  pq.push(20);
  pq.push(50);
  cout << "Size of priority queue: " << pq.size() << endl;

  while (!pq.empty()) {
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
  }
}

void reversedPQ() {
  // Using std::priority_queue with reversed order
  cout << "* Reversed priority queue using std::priority_queue" << endl;
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(30);
  pq.push(20);
  pq.push(50);
  cout << "Size of reversed priority queue: " << pq.size() << endl;

  while (!pq.empty()) {
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
  }
}

void pairInPQ() {
  // Using std::priority_queue with pairs
  cout << "* Priority queue with pairs using std::priority_queue" << endl;
  priority_queue<pair<int, int>> pq;
  pq.push({30, 10}); // same as make_pair(30, 10)
  pq.push({20, 2});
  pq.push({50, 3});
  cout << "Size of priority queue with pairs: " << pq.size() << endl;

  while (!pq.empty()) {
    cout << "Top element: (" << pq.top().first << ", " << pq.top().second << ")"
         << endl;
    pq.pop();
  }
}

class A {
public:
  int x;
  // Default constructor
  A(int x) : x(x) { cout << "A(int) created with x = " << x << endl; }
  // Copy constructor
  //   A(const A &a) : x(a.x) {
  //     cout << "A(const A&) created with x = " << x << endl;
  //   }
  bool operator<(const A &other) const {
    // Define the comparison for priority queue
    return x < other.x; // For max-heap, use '>' for min-heap
  }
};

void objectInPQ() {
  // Using std::priority_queue with objects
  cout << "* Priority queue with objects using std::priority_queue" << endl;
  priority_queue<A> pq;
  pq.push(A(30));
  pq.push(A(20));
  pq.push(A(50));
  cout << "Size of priority queue with objects: " << pq.size() << endl;

  while (!pq.empty()) {
    cout << "Top element: " << pq.top().x << endl;
    pq.pop();
  }
}

class B {
public:
  int x;
  // Default constructor
  B(int x) : x(x) { cout << "B(int) created with x = " << x << endl; }
  // Copy constructor
  //   B(const B &a) : x(a.x) {
  //     cout << "B(const B&) created with x = " << x << endl;
  //   }
};

bool myBOpCmp(B *lhs, B *rhs) {
  // Define the comparison for priority queue
  return lhs->x < rhs->x; // '<' is for max-heap, use '>' for min-heap
}

void pointerInPQ() {
  // Using std::priority_queue with pointers
  cout << "* Priority queue with pointers using std::priority_queue" << endl;
  priority_queue<B *, vector<B *>, decltype(&myBOpCmp)> pq(&myBOpCmp);
  // Same as below. decltype returns the type, a function pointer in this case
  // priority_queue<B *, vector<B *>, bool (*)(B *, B *)> pq(&myBOpCmp);
  pq.push(new B(30));
  pq.push(new B(20));
  pq.push(new B(50));
  cout << "Size of priority queue with pointers: " << pq.size() << endl;

  while (!pq.empty()) {
    cout << "Top element: " << pq.top()->x << endl;
    delete pq.top(); // Free the memory
    pq.pop();
  }
}

int main() {
  defaultPQ();
  reversedPQ();
  pairInPQ();
  objectInPQ();
  pointerInPQ();
  return 0;
}