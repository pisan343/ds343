#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void vectorOps() {
  // Using std::vector
  cout << "* Vector using std::vector" << endl;
  vector<int> vec = {10, 20, 30, 40, 50};
  cout << "Size of vector: " << vec.size() << " elements" << endl;

  // Index based access
  cout << "Index based access:" << endl;
  for (size_t i = 0; i < vec.size(); i++) {
    cout << "Element " << i << ": " << vec[i] << endl;
  }

  // Range based access
  cout << "Range based access:" << endl;
  for (int x : vec) {
    cout << "Element: " << x << endl;
  }

  // Find max element
  vector<int>::iterator itMax = max_element(vec.begin(), vec.end());
  cout << "Max element: " << *itMax << endl;

  // Find min element
  vector<int>::iterator itMin = min_element(vec.begin(), vec.end());
  cout << "Min element: " << *itMin << endl;

  // True if all elements are even
  bool allEven =
      all_of(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });

  // For sorted vectors, we can use binary search
  sort(vec.begin(), vec.end()); // Ensure the vector is sorted
  bool found20 = binary_search(vec.begin(), vec.end(), 20);
  cout << "Element 20 found in sorted vector: " << (found20 ? "Yes" : "No")
       << endl;

  // Adding elements
  vec.push_back(60);
  vec.push_back(70);
  assert(!vec.empty());
  // Remove last element
  vec.pop_back();
}

class A {
public:
  int x;
  // Default constructor
  A(int x) : x(x) { cout << "A(int) created with x = " << x << endl; }
  // Copy constructor
  A(const A &a) : x(a.x) {
    cout << "A(const A&) created with x = " << x << endl;
  }
};

void objectInVector() {
  // Using std::vector with objects
  cout << "* Vector with objects" << endl;
  A a0(1);
  A a1(10);
  vector<A> vecA;
  // Uses copy constructor
  vecA.push_back(a0);
  vecA.push_back(a1);
  a0.x = 7;
  // Modifying a0.x does not affect vecA[0].x
  cout << "After modifying a0.x, vecA[0].x = " << vecA[0].x << endl;
}

int main() {
  vectorOps();
  objectInVector();
  return 0;
}
