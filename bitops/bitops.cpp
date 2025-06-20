#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

void bitwiseOperations() {
  // Bitwise operations
  int a = 5; // 0101 in binary
  int b = 3; // 0011 in binary

  // AND operation - 0101 & 0011 = 0001
  cout << "a & b: " << (a & b) << endl;
  // OR operation - 0101 | 0011 = 0111
  cout << "a | b: " << (a | b) << endl;
  // XOR operation - 0101 ^ 0011 = 0110
  // XOR is true if bits are different
  cout << "a ^ b: " << (a ^ b) << endl;
  // NOT operation - ~0101 = 1010 (inverts all bits)
  // Note: ~ operator gives the two's complement in C++
  // For positive numbers, it will give a negative result due to how integers
  // are represented in memory
  // For example, ~5 (0101) will give -6 (1010 in two's complement)
  cout << "~a: " << (~a) << endl;
  // Left shift -- 0101 << 1 = 1010 (10 in decimal)
  // Multiplying by 2
  cout << "a << 1: " << (a << 1) << endl;
  // Right shift -- 0101 >> 1 = 0010 (2 in decimal)
  // Dividing by 2
  cout << "a >> 1: " << (a >> 1) << endl;
}

bool isEven(int n) {
  // Check if the least significant bit is 0
  return (n & 1) == 0;
}

bool isDivisibleByFour(int n) {
  // Check if the two least significant bits are 00
  return (n & 3) == 0;
}

int findSingleNumber(const vector<int> &nums) {
  int result = 0;
  for (int num : nums) {
    result ^= num; // XOR all numbers
  }
  return result; // The single number will remain after all pairs cancel out
}

void setBit(unsigned int &num, int bitPosition) {
  // Set the bit at bitPosition to 1
  num |= (1 << bitPosition);
}
void clearBit(unsigned int &num, int bitPosition) {
  // Clear the bit at bitPosition to 0
  num &= ~(1 << bitPosition);
}
bool isBitSet(unsigned int num, int bitPosition) {
  // Check if the bit at bitPosition is set
  return (num & (1 << bitPosition)) != 0;
}

int main() {
  bitwiseOperations();
  int num = 10;
  cout << "Is " << num << " even? " << (isEven(num) ? "Yes" : "No") << endl;
  cout << "Is " << num << " divisible by 4? "
       << (isDivisibleByFour(num) ? "Yes" : "No") << endl;
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << "The single number in the array is: " << findSingleNumber(nums)
       << endl;
  unsigned int bitNum = 0b1010; // 10 in binary
  cout << "Original number: " << bitNum << endl;
  setBit(bitNum, 2); // Set the 2nd bit
  cout << "After setting 2nd bit: " << bitNum << endl;
  clearBit(bitNum, 1); // Clear the 1st bit
  cout << "After clearing 1st bit: " << bitNum << endl;
  cout << "Is the 3rd bit set? " << (isBitSet(bitNum, 3) ? "Yes" : "No")
       << endl;
  return 0;
}