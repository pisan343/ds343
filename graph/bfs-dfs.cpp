#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

bool bfs(const vector<vector<int>> &graph, int start, int target) {
  queue<int> q;
  unordered_set<int> visited;
  q.push(start);
  visited.insert(start);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    if (node == target) {
      return true; // Target found
    }
    for (int neighbor : graph[node]) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
  }
  return false; // Target not found
}

bool dfs(const vector<vector<int>> &graph, int start, int target) {
  stack<int> s;
  unordered_set<int> visited;
  s.push(start);
  visited.insert(start);

  while (!s.empty()) {
    int node = s.top();
    s.pop();
    if (node == target) {
      return true; // Target found
    }
    for (int neighbor : graph[node]) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        s.push(neighbor);
      }
    }
  }
  return false; // Target not found
}

bool defRecursive(const vector<vector<int>> &graph, int node, int target,
                  unordered_set<int> &visited) {
  if (node == target) {
    return true; // Target found
  }
  visited.insert(node);
  for (int neighbor : graph[node]) {
    if (visited.find(neighbor) == visited.end()) {
      if (defRecursive(graph, neighbor, target, visited)) {
        return true; // Target found in recursive call
      }
    }
  }
  return false; // Target not found in this path
}

bool isReachable(const vector<pair<int, int>> &edges, int start, int target) {
  // Create an adjacency list from the edges
  // Assuming node values are in range [0, 99]
  // Alternative would be to use
  //       unordered_map<int, vector<int>> for dynamic node values
  vector<vector<int>> graph(100);
  for (const auto &edge : edges) {
    graph[edge.first].push_back(edge.second);
    graph[edge.second].push_back(edge.first); // For bi-directional graph
  }
  bool foundBFS = bfs(graph, start, target);
  bool foundDFS = dfs(graph, start, target);
  unordered_set<int> visited; // For recursive DFS
  bool foundDFSRecursive = defRecursive(graph, start, target, visited);
  cout << "BFS found target: " << target << " " << (foundBFS ? "Yes" : "No")
       << endl;
  cout << "DFS found target: " << target << " " << (foundDFS ? "Yes" : "No")
       << endl;
  cout << "DFS Recursive found target: " << target << " "
       << (foundDFSRecursive ? "Yes" : "No") << endl;
  assert(foundBFS == foundDFS && foundDFS == foundDFSRecursive);
  return foundBFS;
}
void graph1() {
  // Bi-directional graph, nodes are integers from 0 to 3
  // Circle of nodes
  // 0 -- 1
  // 1 -- 2
  // 2 -- 3
  // 3 -- 0
  cout << "Graph 1:" << endl;
  vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
  bool reach7 = isReachable(edges, 0, 7);
  cout << "Is node 7 reachable from node 0? " << (reach7 ? "Yes" : "No")
       << endl;
  bool reach3 = isReachable(edges, 0, 3);
  cout << "Is node 3 reachable from node 0? " << (reach3 ? "Yes" : "No")
       << endl;
}

void graph2() {
  // Bi-directional graph, nodes are integers from 0 to 3
  // Tree like structure
  // 0 -- 1, 0 -- 2
  // 1 -- 3, 1 -- 4
  // 2 -- 5, 2 -- 6
  // 3 -- 7, 4 -- 8
  cout << "Graph 2:" << endl;
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4},
                                  {2, 5}, {2, 6}, {3, 7}, {4, 8}};
  bool reach7 = isReachable(edges, 0, 7);
  cout << "Is node 7 reachable from node 0? " << (reach7 ? "Yes" : "No")
       << endl;
  bool reach8 = isReachable(edges, 0, 8);
  cout << "Is node 8 reachable from node 0? " << (reach8 ? "Yes" : "No")
       << endl;
  bool reach20 = isReachable(edges, 0, 20);
  cout << "Is node 20 reachable from node 0? " << (reach20 ? "Yes" : "No")
       << endl;
}

int main() {
  graph1();
  graph2();
  return 0;
}
