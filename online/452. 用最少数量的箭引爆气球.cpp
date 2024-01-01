#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 贪心算法。首先按照气球的结束坐标进行升序排序，然后从左到右扫描，
// 维护一个当前箭所能达到的最远结束坐标，如果下一个气球的开始坐标在当前箭的最远结束坐标之后，说明需要一支新的箭。

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

int main() {
  vector<vector<int>> points1 = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << findMinArrowShots(points1) << endl; // 输出 2

  vector<vector<int>> points2 = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  cout << findMinArrowShots(points2) << endl; // 输出 4

  vector<vector<int>> points3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  cout << findMinArrowShots(points3) << endl; // 输出 2
  return 0;
}
