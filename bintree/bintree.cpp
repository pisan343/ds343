#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

void preorderTraversal(Node *root) {
  if (root == nullptr)
    return;
  cout << root->val << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
void inorderTraversal(Node *root) {
  if (root == nullptr)
    return;
  inorderTraversal(root->left);
  cout << root->val << " ";
  inorderTraversal(root->right);
}
void postorderTraversal(Node *root) {
  if (root == nullptr)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->val << " ";
}

// Similar to breadth-first search (BFS) for trees
void levelOrderTraversal(Node *root) {
  if (root == nullptr)
    return;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *current = q.front();
    q.pop();
    cout << current->val << " ";
    if (current->left != nullptr)
      q.push(current->left);
    if (current->right != nullptr)
      q.push(current->right);
  }
}
void deleteTree(Node *root) {
  if (root == nullptr)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
void testBinaryTree() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout << "Preorder Traversal: ";
  preorderTraversal(root);
  cout << endl;

  cout << "Inorder Traversal: ";
  inorderTraversal(root);
  cout << endl;

  cout << "Postorder Traversal: ";
  postorderTraversal(root);
  cout << endl;

  cout << "Level Order Traversal: ";
  levelOrderTraversal(root);
  cout << endl;

  deleteTree(root);
}

int main() {
  testBinaryTree();
  cout << "Binary tree tests completed successfully." << endl;
  return 0;
}