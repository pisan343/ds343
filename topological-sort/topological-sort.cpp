#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Topological sort
// Given a directed graph, what order do we need to visit vertices
// Typical example: Course prerequisites

// https://leetcode.com/problems/course-schedule/description/
// The pair [0, 1],
// indicates that to take course 0 you have to first take course 1.
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  // Create a graph from the prerequisites
  vector<vector<int>> graph(numCourses);
  vector<int> inDegree(numCourses, 0);
  for (const auto &pre : prerequisites) {
    int course = pre[0];
    int prerequisite = pre[1];
    graph[prerequisite].push_back(course);
    inDegree[course]++;
  }

  // Perform a topological sort using Kahn's algorithm
  queue<int> q;
  for (int i = 0; i < numCourses; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }

  int count = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    count++;

    for (int neighbor : graph[curr]) {
      inDegree[neighbor]--;
      if (inDegree[neighbor] == 0) {
        q.push(neighbor);
      }
    }
  }

  // If we were able to visit all courses, return true
  return count == numCourses;
}

int main() {
  int numCourses = 2;
  vector<vector<int>> prerequisites = {{1, 0}};
  assert(canFinish(numCourses, prerequisites) == true);

  numCourses = 2;
  prerequisites = {{1, 0}, {0, 1}};
  assert(canFinish(numCourses, prerequisites) == false);

  numCourses = 3;
  prerequisites = {{0, 1}, {1, 2}};
  assert(canFinish(numCourses, prerequisites) == true);

  cout << "All tests passed!" << endl;
  return 0;
}