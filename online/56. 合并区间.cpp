#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 首先将区间按照起始位置进行排序，然后逐个比较相邻的区间是否有重叠，有重叠则合并，没有重叠则加入结果。

vector<vector<int>> merge(vector<vector<int>> &intervals) {
  if (intervals.empty()) {
    return {};
  }

  // 按照去阿金的其实位置进行排序
  sort(intervals.begin(), intervals.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  vector<vector<int>> result;
  result.emplace_back(intervals[0]);

  for (int i = 1; i < intervals.size(); ++i) {
    if (result.back()[1] >= intervals[i][0]) {
      // 有重叠的，合并重叠区间
      result.back()[1] = max(result.back()[1], intervals[i][1]);
    } else {
      // 无重叠, 加入结果
      result.emplace_back(intervals[i]);
    }
  }
  return result;
}

int main() {
  // 示例用法
  vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> result1 = merge(intervals1);
  for (const auto &interval : result1) {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl; // 输出 [[1,6],[8,10],[15,18]]

  vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
  vector<vector<int>> result2 = merge(intervals2);
  for (const auto &interval : result2) {
    cout << "[" << interval[0] << "," << interval[1] << "] ";
  }
  cout << endl; // 输出 [[1,5]]
  return 0;
}
