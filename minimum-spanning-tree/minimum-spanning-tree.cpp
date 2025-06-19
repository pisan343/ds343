#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Minimum Spanning Tree
// Given a connected, undirected graph, find a subset of edges that connects all
// vertices without cycles and with the minimum possible total edge weight.
// Typical example: Network design, road construction

// Prim's algorithm
// https://leetcode.com/problems/minimum-cost-to-connect-sticks/description/
int minCostConnectSticks(vector<int> &sticks) {
  priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(),
                                                    sticks.end());
  int totalCost = 0;
  while (pq.size() > 1) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();
    int cost = first + second;
    cout << "Connecting sticks of lengths " << first << " and " << second
         << " with cost: " << cost << endl;
    totalCost += cost;
    pq.push(cost);
  }
  return totalCost;
}

// Kruskal's algorithm
// Involves sorting edges and using a union-find data structure to avoid cycles.
class DSU {
public:
  vector<int> parent, rank;
  DSU(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }
  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]); // Path compression
    }
    return parent[u];
  }
  void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
      if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
      } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
      } else {
        parent[rootV] = rootU;
        rank[rootU]++;
      }
    }
  }
  bool connected(int u, int v) { return find(u) == find(v); }
};
struct Edge {
  int u, v, weight;
  Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compareEdges(const Edge &a, const Edge &b) { return a.weight > b.weight; }

int totalLength(vector<Edge> &edges) {
  priority_queue<Edge, vector<Edge>, decltype(&compareEdges)> pq(compareEdges);
  for (const auto &edge : edges) {
    pq.push(edge);
  }
  DSU dsu(1000); // Assuming a max of 1000 vertices
  int total = 0;
  while (!pq.empty()) {
    Edge edge = pq.top();
    pq.pop();
    cout << "Processing edge: " << edge.u << " - " << edge.v
         << " with weight: " << edge.weight << endl;
    if (!dsu.connected(edge.u, edge.v)) {
      cout << "Adding edge: " << edge.u << " - " << edge.v
           << " with weight: " << edge.weight << endl;
      dsu.unionSets(edge.u, edge.v);
      total += edge.weight;
    }
  }
  return total;
}

int main() {
  vector<int> sticks = {1, 2, 3};
  int result = minCostConnectSticks(sticks);
  cout << "Prim: Minimum cost to connect sticks: " << result << endl << endl;

  // Example edges for Kruskal's algorithm
  vector<Edge> edges = {Edge(0, 1, 10), Edge(0, 2, 6), Edge(0, 3, 5),
                        Edge(1, 3, 15), Edge(2, 3, 4)};
  int total = totalLength(edges);
  cout << "Kruskal: Total length of minimum spanning tree: " << total << endl;
  return 0;
}