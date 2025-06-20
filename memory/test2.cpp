#include <cassert>
#include <iostream>

using namespace std;

class NodeTest2 {
  friend ostream &operator<<(ostream &out, const NodeTest2 &n) {
    out << "N<" << n.value << ", " << (n.next != nullptr) << ">";
    return out;
  }

public:
  static int nodeCount;
  int value;
  NodeTest2 *next;

  explicit NodeTest2(int value = 0, NodeTest2 *next = nullptr)
      : value{value}, next{next} {
    ++nodeCount;
    cout << "Creating " << *this << ", total created: " << nodeCount << endl;
  }
  ~NodeTest2() {
    cout << "Deleting: " << *this;
    --nodeCount;
    cout << ", nodes remaining: " << nodeCount << endl;
  }
};

int NodeTest2::nodeCount = 0;

NodeTest2 *find(NodeTest2 *start, int value) {
  assert(start != nullptr);
  NodeTest2 *curr = start;
  while (curr != nullptr && curr->value != value)
    curr = curr->next;
  return curr;
}

// insert B after A, return B
NodeTest2 *addAfter(NodeTest2 *a, NodeTest2 *b) {
  assert(a != nullptr && b != nullptr);
  NodeTest2 *c = a->next;
  a->next = b;
  b->next = c;
  return b;
}

// Given the head of the list, find Node with ValB, insert A to come before B
NodeTest2 *addBefore(NodeTest2 *start, int valA, int valB) {
  assert(start != nullptr);
  NodeTest2 *nodeB = find(start, valB);
  auto *nodeA = new NodeTest2(valA);
  nodeA->next = nodeB;
  NodeTest2 *curr = start;
  while (curr->next != nodeB)
    curr = curr->next;
  curr->next = nodeA;
  return start;
}

NodeTest2 *remove(NodeTest2 *start, NodeTest2 *n) {
  assert(start != nullptr);
  NodeTest2 *curr = start;
  while (curr != nullptr && curr->next != n)
    curr = curr->next;
  if (curr != nullptr)
    curr->next = n->next;
  return start;
}

void displayAll(NodeTest2 *n) {
  cout << "[";
  if (n != nullptr) {
    cout << *n;
    n = n->next;
  }
  while (n != nullptr) {
    cout << ", " << *n;
    n = n->next;
  }
  cout << "]" << endl;
}

void test2() {
  auto *head = new NodeTest2(100);
  NodeTest2 *tail = head;
  for (int i = 1; i <= 5; ++i) {
    tail = addAfter(tail, new NodeTest2(i * i * i));
  }
  displayAll(head);
  addBefore(head, 7, 8);
  addBefore(head, 13, 125);
  addBefore(head, 15, 9);
  addBefore(head, 17, 11);

  addBefore(head, 19, 100);
  displayAll(head);
  remove(head, find(head, 8));
  remove(head, find(head, 77));
  remove(head, find(head, 100));
  remove(head, find(head, 19));
  displayAll(head);
}
