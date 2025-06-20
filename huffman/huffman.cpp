#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Huffman coding
// Given a set of characters and their frequencies, build a binary tree
// such that the characters with higher frequencies have shorter codes.
// Typical example: Data compression, file storage
struct Node {
  char ch;
  int freq;
  Node *left, *right;
  Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
  bool operator()(Node *a, Node *b) {
    return a->freq > b->freq; // Min-heap based on frequency
  }
};

Node *buildHuffmanTree(const vector<pair<char, int>> &freqs) {
  priority_queue<Node *, vector<Node *>, Compare> pq;

  // Create a leaf node for each character and add it to the priority queue
  for (const auto &pair : freqs) {
    pq.push(new Node(pair.first, pair.second));
  }

  // Build the Huffman tree
  while (pq.size() > 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    Node *newNode = new Node('\0', left->freq + right->freq);
    newNode->left = left;
    newNode->right = right;
    pq.push(newNode);
  }

  return pq.top(); // The root of the Huffman tree
}

void printHuffmanCodes(Node *root, const string &code) {
  if (!root)
    return;

  // If this is a leaf node, print the character and its code
  if (!root->left && !root->right) {
    cout << root->ch << ": " << code << endl;
    return;
  }

  // Traverse left and right subtrees
  printHuffmanCodes(root->left, code + "0");
  printHuffmanCodes(root->right, code + "1");
}

void cleanUp(Node *root) {
  if (!root)
    return;
  cleanUp(root->left);
  cleanUp(root->right);
  delete root; // Free memory
}

int main() {
  vector<pair<char, int>> freqs = {{'a', 5},  {'b', 9},  {'c', 12},
                                   {'d', 13}, {'e', 16}, {'f', 45}};

  Node *root = buildHuffmanTree(freqs);
  cout << "Huffman Codes:" << endl;
  printHuffmanCodes(root, "");

  // Clean up memory
  cleanUp(root);
  return 0;
}
