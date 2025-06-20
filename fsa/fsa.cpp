#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Finite State Automaton (FSA)
// Start from State 0 and transition based on input
int main() {
  // Define the transition table
  vector<vector<int>> transitionTable = {
      {1, 2, -1}, // State 0: input 0 -> State 1, input 1 -> State 2, input 2 ->
                  // Invalid (-1)
      {0, -1, -1}, // State 1: input 0 -> State 0, input 1 -> Invalid (-1),
                   // input 2 -> Invalid (-1)
      {-1, 0, -1} // State 2: input 0 -> Invalid (-1), input 1 -> State 0, input
                  // 2 -> Invalid (-1)
  };

  // Define the initial state
  int currentState = 0;

  // Process input
  int input;
  while (true) {
    cout << "Enter input (0-2) or -1 to exit: ";
    cin >> input;
    if (input == -1)
      break;

    // Transition to the next state
    if (input >= 0 && input < transitionTable[currentState].size()) {
      currentState = transitionTable[currentState][input];
      if (currentState == -1) {
        cout << "Invalid transition. Resetting to State 0." << endl;
        currentState = 0;
      }
    } else {
      cout << "Invalid input. Please enter 0-2." << endl;
    }

    cout << "Current State: " << currentState << endl;
  }

  return 0;
}