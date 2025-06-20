#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Box {
public:
  int val;
  int *iptr;
  Box(int val) : val{val} {
    cout << "Box created: " << val << endl;
    iptr = new int[10];
  }
  ~Box() { cout << "Box deleted: " << val << endl; }
};

void test4() {
  Box b1(10);
  Box b2(b1);
}