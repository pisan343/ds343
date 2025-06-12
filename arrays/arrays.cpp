#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

void arrOnStackHelper(int *myArray) {
  // This function receives a pointer to an array
  // Size of the pointer is 8 bytes on most systems
  // The size of the array is not known here, only the size of the pointer
  cout << "Size of myArray in arrOnStackHelper: " << sizeof(myArray) << " bytes"
       << endl;
  // Cannot use std::size here, as myArray is a pointer, not an array
}

void arrOnStack() {
  // Block of contiguous memory
  cout << "* Array on stack" << endl;
  int arr[5] = {10, 20, 30, 40, 50};
  cout << "Array address: " << arr << endl;
  u_int64_t first = (u_int64_t)&arr[0];
  u_int64_t second = (u_int64_t)&arr[1];
  cout << "First element address: " << first;
  cout << " or " << std::hex << first << " in hex" << std::dec << endl;
  cout << "Second element address: " << second;
  cout << " or " << std::hex << second << " in hex" << std::dec << endl;
  // Integers are 4 bytes on most systems, 32 bits
  cout << "Each integer is " << (second - first) << " bytes" << endl;
  u_int64_t last = first + 4 * sizeof(int);
  int *lastElement = (int *)last;
  cout << "Last element address: " << lastElement << endl;
  cout << "Last element value: " << *lastElement << endl;
  // Pointer arithmetic
  cout << "Last element using pointer arithmetic: " << *(arr + 4) << endl;
  // Out of bounds access, undefined behavior
  cout << "Out of bounds access: " << *(arr + 5) << endl;
  // Size of array - 20 bytes (5 integers * 4 bytes each)
  cout << "Size of array using sizeof: " << sizeof(arr) << " bytes" << endl;
  // C++17 introduced std::size - 5 elements
  cout << "Size of array using std::size: " << std::size(arr) << " elements"
       << endl;
  arrOnStackHelper(arr);
}

void arrOnHeap() {
  // Dynamic memory allocation
  cout << "* Array on heap" << endl;
  int *arr = new int[5]{10, 20, 30, 40, 50};
  // everything is same as array on stack except arr is now a pointer
  // Size of the pointer is 8 bytes on most systems
  cout << "Size of arr in arrOnHeap: " << sizeof(arr) << " bytes" << endl;
  // Clean up memory
  delete[] arr;
  // C++ standard does not allow creating arrays on the stack where the size is
  // not known at compile time. This is why we use dynamic memory allocation for
  // arrays of unknown size
  // However, Variable Length Arrays (VLAs) are allowed in some compilers as an
  // extension
  cout << "Enter a number for VLA (such as 10): ";
  int n;
  cin >> n;
  int vla[n];
  cout << "Size of VLA: " << sizeof(vla) << " bytes" << endl;
  // Do not use VLAs in production code, they are not part of the C++ standard
  // and can lead to undefined behavior if not used carefully
}

void arrSTL() {
  // Using std::array
  cout << "* Array using std::array" << endl;
  array<int, 5> arr = {10, 20, 30, 40, 50};
  cout << "Array address: " << arr.data() << endl;
  cout << "Size of array using std::array: " << arr.size() << " elements"
       << endl;
}

void arrCommonOps() {
  // Common operations on arrays
  cout << "* Common operations on arrays" << endl;
  const int n = 5;
  int arr[n] = {10, 20, 30, 40, 50};
  // Index based access
  cout << "Index based access:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Element " << i << ": " << arr[i] << endl;
  }
  // Range based access
  cout << "Range based access:" << endl;
  for (int x : arr) {
    cout << "Element: " << x << endl;
  }

  // Find max element
  int *itMax = max_element(arr, arr + n);
  cout << "Max element: " << *itMax << endl;
  // Find min element
  int *itMin = min_element(arr, arr + n);
  cout << "Min element: " << *itMin << endl;

  // True if all elements are even
  bool allEven = all_of(arr, arr + n, [](int x) { return x % 2 == 0; });
  // True if any element is greater than 25
  bool anyGreaterThan25 = any_of(arr, arr + n, [](int x) { return x > 25; });
  // True if no element is less than 10
  bool noneLessThan10 = none_of(arr, arr + n, [](int x) { return x < 10; });
  cout << "All elements are even: " << (allEven ? "Yes" : "No") << endl;
  cout << "Any element greater than 25: " << (anyGreaterThan25 ? "Yes" : "No")
       << endl;
  cout << "No element less than 10: " << (noneLessThan10 ? "Yes" : "No")
       << endl;

  // For sorted arrays, we can use binary search
  sort(arr, arr + n); // Ensure the array is sorted
  bool found20 = binary_search(arr, arr + n, 20);
  cout << "Element 20 found in sorted array: " << (found20 ? "Yes" : "No")
       << endl;
  // Reverse the array
  reverse(arr, arr + n);
  cout << "Reversed array: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
  // Swap first and last elements
  swap(arr[0], arr[4]);
  // Alternatively, using pointers, second and third elements
  swap(*(arr + 1), *(arr + 2));
  cout << "After swapping first and last elements: ";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  arrOnStack();
  arrOnHeap();
  arrSTL();
  arrCommonOps();
  return 0;
}