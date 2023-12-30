#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  vector<vector<int>> result;
  int i = 0;

  // 将新区建之前的不重叠的区间加入结果
  while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
    result.emplace_back(intervals[i]);
    ++i;
  }

  // 合并重叠区间
  while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    ++i;
  }
  result.emplace_back(newInterval);

  // 将新区间之后的不重叠区间加入结果
  while (i < intervals.size()) {
    result.emplace_back(intervals[i]);
    ++i;
  }
  return result;
}

int main() {
  // 示例用法
  vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
  vector<int> newInterval1 = {2, 5};
  vector<vector<int>> result1 = insert(intervals1, newInterval1);
  for (const auto &interval : result1) {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl; // 输出 [[1,5],[6,9]]

  vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval2 = {4, 8};
  vector<vector<int>> result2 = insert(intervals2, newInterval2);
  for (const auto &interval : result2) {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl; // 输出 [[1,2],[3,10],[12,16]]
  return 0;
}
