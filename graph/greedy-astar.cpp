#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Using heuristic function to estimate the cost from current node to target

unordered_map<string, unordered_map<string, int>> graph = {
    {"Arad", {{"Zerind", 75}, {"Sibiu", 140}, {"Timisoara", 118}}},
    {"Zerind", {{"Arad", 75}, {"Oradea", 71}}},
    {"Oradea", {{"Zerind", 71}, {"Sibiu", 151}}},
    {"Sibiu",
     {{"Arad", 140}, {"Oradea", 151}, {"Fagaras", 99}, {"Rimnicu Vilcea", 80}}},
    {"Fagaras", {{"Sibiu", 99}, {"Pitesti", 101}, {"Bucharest", 178}}},
    {"Pitesti", {{"Fagaras", 101}, {"Rimnicu Vilcea", 97}, {"Bucharest", 98}}},
    {"Bucharest", {{"Pitesti", 98}, {"Fagaras", 178}}},
    {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
    {"Lugoj", {{"Timisoara", 111}, {"Mehadia", 70}}},
    {"Mehadia", {{"Lugoj", 70}, {"Drobeta", 75}}},
    {"Drobeta", {{"Mehadia", 75}, {"Craiova", 120}}},
    {"Craiova", {{"Drobeta", 120}, {"Rimnicu Vilcea", 146}}},
    {"Rimnicu Vilcea", {{"Craiova", 146}, {"Sibiu", 80}, {"Pitesti", 97}}},
    {"Bucharest", {{"Fagaras", 178}, {"Pitesti", 98}}}};

unordered_map<string, int> distanceToBucharest = {
    {"Arad", 366},           {"Zerind", 374},    {"Oradea", 380},
    {"Sibiu", 253},          {"Timisoara", 329}, {"Lugoj", 244},
    {"Mehadia", 241},        {"Drobeta", 242},   {"Craiova", 160},
    {"Rimnicu Vilcea", 193}, {"Pitesti", 98},    {"Fagaras", 178},
    {"Bucharest", 0}};

int heuristic(const string &node) {
  auto it = distanceToBucharest.find(node);
  if (it != distanceToBucharest.end()) {
    return it->second;
  }
  return INT_MAX; // Return a large value if node not found
}

int greedySearch(const string &start, const string &target) {
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
  unordered_set<string> visited;

  pq.push({heuristic(start), start});

  cout << "Greedy Search: Starting from " << start << " to " << target << endl;
  while (!pq.empty()) {
    auto [currentCost, currentNode] = pq.top();
    pq.pop();
    cout << endl
         << "Visiting: " << currentNode << " with cost: " << currentCost
         << endl;

    if (currentNode == target) {
      return currentCost; // Return the cost to reach the target
    }

    if (visited.count(currentNode)) {
      continue; // Skip if already visited
    }
    visited.insert(currentNode);

    for (const auto &[neighbor, weight] : graph.at(currentNode)) {
      cout << "Greedy: Considering neighbor: " << neighbor
           << " with heuristic cost: " << heuristic(neighbor) << endl;
      pq.push({heuristic(neighbor), neighbor});
    }
  }
  return -1; // Target not reachable
}
int aStar(const string &start, const string &target) {
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
  unordered_map<string, int> gScore;      // Cost from start to current node
  unordered_map<string, string> cameFrom; // To reconstruct the path
  unordered_set<string> visited;

  gScore[start] = 0;
  pq.push({heuristic(start), start});

  cout << "A* Search: Starting from " << start << " to " << target << endl;
  while (!pq.empty()) {
    auto [currentCost, currentNode] = pq.top();
    pq.pop();
    cout << endl
         << "Visiting: " << currentNode << " with cost: " << currentCost
         << endl;
    if (currentNode == target) {
      // Reconstruct the path if needed
      vector<string> path;
      for (string at = target; at != start; at = cameFrom[at]) {
        path.push_back(at);
      }
      path.push_back(start);
      reverse(path.begin(), path.end());
      cout << "Path: ";
      for (const auto &node : path) {
        cout << node << " ";
      }
      cout << endl;
      return gScore[target]; // Return the cost to reach the target
    }

    if (visited.count(currentNode)) {
      continue; // Skip if already visited
    }
    visited.insert(currentNode);

    for (const auto &[neighbor, weight] : graph.at(currentNode)) {
      int tentativeGScore = gScore[currentNode] + weight;
      cout << "A*: Considering neighbor: " << neighbor
           << " with tentative G-Score: " << tentativeGScore << endl;
      if (gScore.find(neighbor) == gScore.end() ||
          tentativeGScore < gScore[neighbor]) {
        gScore[neighbor] = tentativeGScore;
        cameFrom[neighbor] = currentNode;
        cout << "Adding: " << tentativeGScore + heuristic(neighbor) << " to "
             << neighbor << endl;
        pq.push({tentativeGScore + heuristic(neighbor), neighbor});
      }
    }
  }
  return -1; // Target not reachable
}

int main() {
  string start = "Arad";
  string target = "Bucharest";
  int greedyDistance = greedySearch(start, target);
  cout << "Greedy Search: Shortest distance from " << start << " to " << target
       << " is " << greedyDistance << endl;

  int aStarDistance = aStar(start, target);
  cout << "A* Search: Shortest aStarDistance from " << start << " to " << target
       << " is " << aStarDistance << endl;
  return 0;
}