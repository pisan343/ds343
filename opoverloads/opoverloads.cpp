#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &vec) {
  os << "[";
  if (!vec.empty()) {
    os << vec[0];
  }
  // Print the rest of the elements
  for (int i = 1; i < vec.size(); ++i) {
    os << ", " << vec[i];
  }
  os << "]";
  return os;
}

void printVector() {
  vector<int> vec = {10, 20, 30, 40, 50};
  cout << vec << endl;
}

class A {
public:
  int x;
  // Default constructor
  A(int x) : x(x) { cout << "A(int) created with x = " << x << endl; }
};

ostream &operator<<(ostream &os, const A &a) {
  os << "A:" << a.x << "";
  return os;
}

void printObject() {
  A a(10);
  cout << a << endl;
}

A operator+(const A &a1, const A &a2) { return A(a1.x + a2.x); }
A operator*(const A &a1, const A &a2) { return A(a1.x * a2.x); }
// Overloading the prefix increment operator
A operator++(A &a) {
  a.x++;
  return a;
}
// Overloading the postfix increment operator
A operator++(A &a, int) {
  A temp = a;
  a.x++;
  return temp;
}

// Overloading the += operator
// Should return a reference to the left operand
// to allow chaining like a1 += a2 += a3;
// This is a common pattern in C++ operator overloading.
// If it returned a copy, it would not allow chaining.
// Returning a reference allows the left operand to be modified directly.
A &operator+=(A &a1, const A &a2) {
  a1.x += a2.x;
  return a1;
}

void opsOnA() {
  A a1(10);
  A a2(20);
  cout << "a1: " << a1 << ", a2: " << a2 << endl;

  // Using overloaded operators
  A sum = a1 + a2;
  cout << "Sum: " << sum << endl;

  A product = a1 * a2;
  cout << "Product: " << product << endl;

  ++a1; // Prefix increment
  cout << "After prefix increment, a1: " << a1 << endl;

  A x = a2++; // Postfix increment
  cout << "After postfix increment, a2: " << a2 << endl;
  cout << "After postfix increment, x: " << x << endl;

  a1 += a2; // Using += operator
  cout << "After +=, a1: " << a1 << endl;
}
int main() {
  printVector();
  printObject();
  opsOnA();
  return 0;
}
