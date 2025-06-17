#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void basicSet() {
  cout << "* Basic set using std::set" << endl;
  std::set<int> s;
  // O(log n) insertion, elements are sorted in ascending order
  s.insert(100);
  s.insert(20);
  s.insert(50);
  assert(s.count(20) == 1); // Check if 20 is in the set
#if __cplusplus >= 202002L
  assert(s.contains(20));
  cout << "Using C++ 20 or later, contains(20) returns: " << s.contains(20)
       << endl;
#endif
  for (int x : s) {
    cout << "Element in set: " << x << endl;
  }
}

void basicMap() {
  cout << "* Basic map using std::map" << endl;
  std::map<int, string> m;
  // O(log n) insertion, elements are sorted by key in ascending order
  m[100] = "hundred";
  m[20] = "twenty";
  m[50] = "fifty";
  assert(m.count(20) == 1); // Check if key 20 is in the map
#if __cplusplus >= 202002L
  assert(m.contains(20));
  cout << "Using C++ 20 or later, contains(20) returns: " << m.contains(20)
       << endl;
#endif
  for (const auto &pair : m) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
  }
}

void basicUnorderedSet() {
  cout << "* Basic unordered set using std::unordered_set" << endl;
  std::unordered_set<int> us;
  // O(1) average time complexity for insertion, elements are not sorted
  us.insert(100);
  us.insert(20);
  us.insert(50);
  assert(us.count(20) == 1); // Check if 20 is in the unordered set
#if __cplusplus >= 202002L
  assert(us.contains(20));
  cout << "Using C++ 20 or later, contains(20) returns: " << us.contains(20)
       << endl;
#endif
  for (int x : us) {
    cout << "Element in unordered set: " << x << endl;
  }
}

void basicUnorderedMap() {
  cout << "* Basic unordered map using std::unordered_map" << endl;
  std::unordered_map<int, string> um;
  // O(1) average time complexity for insertion, elements are not sorted
  um[100] = "hundred";
  um[20] = "twenty";
  um[50] = "fifty";
  assert(um.count(20) == 1); // Check if key 20 is in the unordered map
#if __cplusplus >= 202002L
  assert(um.contains(20));
  cout << "Using C++ 20 or later, contains(20) returns: " << um.contains(20)
       << endl;
#endif
  for (const auto &pair : um) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
  }
}
int main() {
  basicSet();
  basicMap();
  basicUnorderedSet();
  basicUnorderedMap();

  return 0;
}