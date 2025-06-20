#include <iostream>
#include <unordered_map>

// Questions
// 1. Why do we need to define a hash function for the class A?
// 2. What is the purpose of the friend declaration in the class A?
// 3. What is the purpose of the hash function in the std namespace?
// 4. How does the hash function work?
// 5. Do we need operator== for the class A? Why or why not?

using namespace std;

class A {
  friend hash<A>;

private:
  string name;

public:
  A(string n) : name(n) {}
  bool operator==(const A &a) const { return name == a.name; }
};

namespace std {

// In C++, the hash class is default constructible function class
// (functor) that provides the default hash function used by STL.
// https://www.geeksforgeeks.org/stdhash-class-in-c-stl/
template <> struct hash<A> {
  size_t operator()(const A &p) const {
    // return hash<string>()(p.name);
    size_t h = 0;
    for (char c : p.name) {
      h = (h << 5) + h + c; // Hash function
    }
    return h;
  }
};
} // namespace std

int main() {
  unordered_map<A, int> m;
  A a1("hello");
  A a2("world");
  cout << "hash of a1: " << hash<A>()(a1) << endl;
  cout << "hash of a2: " << hash<A>()(a2) << endl;
  m[a1] = 1;
  m[a2] = 2;
  cout << m[a1] << endl; // Output: 1
  cout << m[a2] << endl; // Output: 2
}