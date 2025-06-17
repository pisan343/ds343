#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void queueOps() {
  // Using std::queue
  // Container adapter that provides FIFO (First In First Out) functionality
  cout << "* Queue using std::queue" << endl;
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  cout << "Queue size: " << q.size() << endl;

  while (!q.empty()) {
    cout << "Front element: " << q.front() << endl;
    q.pop();
  }
}
void stackOps() {
  // Using std::stack
  // Container adapter that provides LIFO (Last In First Out) functionality
  cout << "* Stack using std::stack" << endl;
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << "Stack size: " << s.size() << endl;

  while (!s.empty()) {
    cout << "Top element: " << s.top() << endl;
    s.pop();
  }
}

int main() {
  queueOps();
  stackOps();
  return 0;
}