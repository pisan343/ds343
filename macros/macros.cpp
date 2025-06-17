#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void basicPredefinedMacros() {
  cout << "* Predefined macros" << endl;
  cout << "Compilation date is " << __DATE__ << endl;
  cout << "Compilation time is " << __TIME__ << endl;
  cout << "File name is " << __FILE__ << endl;
  cout << "Line number is " << __LINE__ << endl;
  cout << "Function name is " << __func__ << endl;
  cout << "C++ standard version is " << __cplusplus << endl;
}

void basicMacros() {
// Processed at compilation time and text replaced
#define PI 3.1415926535897932384626433L
  cout << "Value of PI is " << PI << endl;
  cout << setprecision(20) << "Value of PI with precision 20 is " << PI << endl;
#define SQUARE(x) (x * x)
  cout << "Square of 5 is " << SQUARE(5) << endl;
  cout << "Square of 5+1 is " << SQUARE(5 + 1) << endl;
#define BETTERSQUARE(x) ((x) * (x))
  cout << "Square of 2+1 using BETTERSQUARE is " << BETTERSQUARE(2 + 1) << endl;

// Basic logging
#define LOG(x)                                                                 \
  cout << __FILE__ ":" << __LINE__ << " DEBUG: " << #x << " = " << x << endl;
  int total = 100;
  LOG(total);
}

int main() {
  basicPredefinedMacros();
  basicMacros();
}