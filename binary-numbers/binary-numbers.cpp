#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Binary numbers
// Decimal 731 is 1 + (3 x 10) + (7 x 100)
// Unit values are 1, 10, 100, 1000, etc.
// Binary 1011010111 is 1 + (1 x 2) + (0 x 4) + (1 x 8) + (1 x 16) +
// (0 x 32) + (1 x 64) + (1 x 128) + (0 x 256) + (1 x 512)
// Unit values are 1, 2, 4, 8, 16, 32, 64

int binaryToDecimal(const string &binary) {
  int decimal = 0;
  int base = 1; // 2^0
  for (int i = binary.size() - 1; i >= 0; --i) {
    if (binary[i] == '1') {
      decimal += base;
    }
    base *= 2; // Move to the next power of 2
  }
  return decimal;
}

// Binary numbers you should know by heart
// 0000 = 0
// 0001 = 1
// 0010 = 2
// 0100 = 4
// 1000 = 8
// 1111 = 15
// 1010 = 10

// Hexadecimal numbers use base 16
// Hexadecimal numbers you should know by heart
// 0x0 = 0
// 0x1 = 1
// ...
// 0x9 = 9
// 0xA = 10
// 0xB = 11
// 0xC = 12
// 0xD = 13
// 0xE = 14
// 0xF = 15

int hexToDecimal(const string &hex) {
  int decimal = 0;
  int base = 1; // 16^0
  for (int i = hex.size() - 1; i >= 0; --i) {
    char digit = hex[i];
    if (digit >= '0' && digit <= '9') {
      decimal += (digit - '0') * base;
    } else if (digit >= 'A' && digit <= 'F') {
      decimal += (digit - 'A' + 10) * base;
    } else {
      cerr << "Invalid hexadecimal digit: " << digit << endl;
      return -1; // Error handling for invalid input
    }
    base *= 16; // Move to the next power of 16
  }
  return decimal;
}

// decimal to binary conversion
string decimalToBinary(int decimal) {
  if (decimal == 0)
    return "0";
  string s;
  while (decimal > 0) {
    int remainder = decimal % 2;
    s = to_string(remainder) + s;
    decimal /= 2;
  }
  return s;
}

// decimal2hexadecimal conversion
string decimalToHex(int decimal) {
  if (decimal == 0)
    return "0";
  string s;
  while (decimal > 0) {
    int remainder = decimal % 16;
    if (remainder < 10) {
      s = to_string(remainder) + s;
    } else {
      s = static_cast<char>('A' + (remainder - 10)) + s;
    }
    decimal /= 16;
  }
  return s;
}

int main() {
  string binary = "1011010111";
  int decimal = binaryToDecimal(binary);
  cout << "Binary: " << binary << " -> Decimal: " << decimal << endl;

  string hex = "1A3F";
  decimal = hexToDecimal(hex);
  cout << "Hexadecimal: " << hex << " -> Decimal: " << decimal << endl;

  return 0;
}