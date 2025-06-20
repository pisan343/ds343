#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Box5 {
public:
  int val;
  int *iptr;
  Box5(int val) : val{val} {
    cout << "Box created: " << val << endl;
    iptr = new int[10];
  }
  ~Box5() { cout << "Box deleted: " << val << endl; }
};

void test5() {
  vector<Box5> boxes;
  for (int i = 0; i < 5; i++) {
    Box5 b5(i);
    boxes.push_back(b5);
  }

  vector<Box5 *> boxptrs;
  for (int i = 0; i < 5; i++) {
    Box5 *bptr = new Box5(i * 100);
    boxptrs.push_back(bptr);
  }
}