#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int dijkstra(const unordered_map<char, unordered_map<char, int>> &graph,
             char start, char target) {
  unordered_map<char, char> previous;
  priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
  unordered_map<char, int> distances;
  unordered_set<char> visited;

  for (const auto &pair : graph) {
    distances[pair.first] = INT_MAX; // Initialize all distances to infinity
  }
  distances[start] = 0; // Distance to start node is 0

  pq.push({0, start});
  while (!pq.empty()) {
    auto [currentDistance, currentNode] = pq.top();
    pq.pop();

    if (currentNode == target) {
      // Reconstruct the path if using the 'previous' map
      vector<char> path;
      for (char at = target; at != start; at = previous[at]) {
        path.push_back(at);
      }
      path.push_back(start);
      reverse(path.begin(), path.end());
      cout << "Path: ";
      for (char node : path) {
        cout << node << " ";
      }
      cout << endl;
      return currentDistance; // Found the target
    }

    if (visited.count(currentNode) == 1) {
      continue; // Skip if already visited. Shorter path already found!
    }
    visited.insert(currentNode);
    // graph.at(currentNode) gives us the neighbors of currentNode
    // in the form of unordered_map<char, int>
    // we cannot use graph[currentNode] because that would allow us
    // to modify the value, but it is passed in as a const reference
    for (const auto [nextNode, weight] : graph.at(currentNode)) {
      int newDistance = currentDistance + weight;
      if (newDistance < distances[nextNode]) {
        // Found a better path to nextNode
        distances[nextNode] = newDistance;
        previous[nextNode] = currentNode;
        pq.push({newDistance, nextNode});
      }
    }
  }
  return -1; // Target not reachable
}

void graph1() {
  // Bi-directional. Distanced from a to b is 4, a to e is 15, a to g is 6, etc.
  // a-b 4, a-e 15, a-g 6, ...
  vector<tuple<char, char, int>> edges = {
      {'a', 'b', 4},  {'a', 'e', 15}, {'a', 'g', 6}, {'b', 'c', 10},
      {'b', 'e', 12}, {'e', 'c', 5},  {'e', 'f', 2}, {'e', 'h', 4},
      {'e', 'g', 9},  {'g', 'h', 13}, {'c', 'd', 7}, {'c', 'f', 9},
      {'h', 'f', 8},  {'h', 'i', 6},  {'d', 'f', 3}, {'d', 'z', 14},
      {'f', 'z', 16}, {'f', 'i', 15}, {'i', 'z', 3}};
  unordered_map<char, unordered_map<char, int>> graph;
  for (const auto &edge : edges) {
    char from = get<0>(edge);
    char to = get<1>(edge);
    int weight = get<2>(edge);
    graph[from][to] = weight;
    graph[to][from] = weight; // For bi-directional graph
  }
  int distanceToZ = dijkstra(graph, 'a', 'z');
  cout << "Distance from a to z: " << distanceToZ << endl;
}

int main() { graph1(); }
