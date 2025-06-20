#include <cassert>
#include <iostream>

using namespace std;

class NodeTest1 {
  friend ostream &operator<<(ostream &out, const NodeTest1 &n) {
    out << "N<" << n.value << ", " << (n.next != nullptr) << ">";
    return out;
  }

public:
  static int nodeCount;
  int value;
  NodeTest1 *next;

  explicit NodeTest1(int value = 0, NodeTest1 *next = nullptr)
      : value{value}, next{next} {
    ++nodeCount;
    cout << "Creating " << *this << ", total created: " << nodeCount << endl;
  }
  ~NodeTest1() {
    cout << "Deleting: " << *this;
    --nodeCount;
    cout << ", nodes remaining: " << nodeCount << endl;
  }
};

int NodeTest1::nodeCount = 0;

void test1() {
  NodeTest1 n1(1);
  NodeTest1 *n1ptr;
  n1ptr = &n1;
  assert(n1ptr != nullptr);
  auto *n2ptr = new NodeTest1(3);
  auto *n3arr = new NodeTest1[10];
  for (int i = 0; i < 5; ++i) {
    NodeTest1 tmp(i * i);
    n3arr[i] = tmp;
  }
  auto n4arr = new NodeTest1 *[10];
  for (int i = 6; i < 10; ++i) {
    auto *tmp = new NodeTest1(i * i);
    n4arr[i] = tmp;
  }
}
