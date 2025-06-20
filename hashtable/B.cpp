#include <iostream>
#include <map>

// Questions
// 1. Do we need operator< for the class B? Why or why not?

using namespace std;

class B {
  friend hash<B>;

private:
  string name;

public:
  B(string n) : name(n) {}
  bool operator<(const B &b) const { return name < b.name; }
};

namespace std {
template <> struct hash<B> {
  size_t operator()(const B &p) const {
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
  map<B, int> m;
  B b1("hello");
  B b2("world");
  cout << "hash of b1: " << hash<B>()(b1) << endl;
  cout << "hash of b2: " << hash<B>()(b2) << endl;
  m[b1] = 1;
  m[b2] = 2;
  cout << m[b1] << endl; // Output: 1
  cout << m[b2] << endl; // Output: 2
}