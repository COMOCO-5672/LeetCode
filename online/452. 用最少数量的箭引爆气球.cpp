#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points) {
  int len1 = points.size();
  sort(points.begin(), points.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
  int removed = 0, prev = points[0][1];
  for (int i = 1; i < len1; ++i) {
    if (points[i][0] <= prev) {
      removed++;
    } else {
      prev = points[i][1];
    }
  }
  return len1 - removed;
}

int main() { return 0; }
