#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// 遍历数组，维护一个当前区间的开始和结束位置，
// 当发现数组元素与当前结束位置不连续时，将当前区间添加到结果中，并更新当前区间的开始和结束位置。

vector<string> summaryRanges(vector<int> &nums) {
  std::vector<std::string> result;
  if (nums.empty()) {
    return result;
  }

  int start = nums[0];
  int end = nums[0];

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == end + 1) {
      end = nums[i];
    } else {
      if (start == end) {
        result.emplace_back(to_string(start));
      } else {
        result.emplace_back(to_string(start) + "->" + to_string(end));
      }
      start = end - start;
    }
  }

  if (start == end) {
    result.emplace_back(to_string(start));
  } else {
    result.emplace_back(to_string(start) + "->" + to_string(end));
  }

  return result;
}

int main() {
  std::vector<int> nums1 = {0, 1, 2, 4, 5, 7};
  std::vector<std::string> result1 = summaryRanges(nums1);

  for (const string &range : result1) {
    std::cout << range << "";
  }

  std::cout << endl;

  vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
  vector<string> result2 = summaryRanges(nums2);
  for (const string &range : result2) {
    cout << range << " ";
  }
  cout << endl; // 输出 "0 2->4 6 8->9"

  vector<int> nums3 = {};
  vector<string> result3 = summaryRanges(nums3);
  for (const string &range : result3) {
    cout << range << " ";
  }
  cout << endl; // 输出 ""

  vector<int> nums4 = {-1};
  vector<string> result4 = summaryRanges(nums4);
  for (const string &range : result4) {
    cout << range << " ";
  }
  cout << endl; // 输出 "-1"

  vector<int> nums5 = {0};
  vector<string> result5 = summaryRanges(nums5);
  for (const string &range : result5) {
    cout << range << " ";
  }
  cout << endl; // 输出 "0"

  return 0;
}
