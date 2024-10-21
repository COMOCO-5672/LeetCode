/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {

private:
  vector<vector<int>> result;
  vector<int> current;

  void backtrack(vector<int> &nums, int target, int start, int count) {
    if (count == 4) {
      if (target == 0) {
        result.push_back(current);
      }
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }

      // 如果当前数字乘以剩余需要选择的数字数量大于target，提前结束
      if ((long long)nums[i] * (4 - count) > target) {
        break;
      }

      // 如果当前数字乘以剩余需要选择的数字数量大于target，提前结束
      if ((long long)nums[i] + (3 - count) * (long long)nums.back() < target) {
        continue;
      }

      current.push_back(nums[i]);
      backtrack(nums, target - nums[i], i + 1, count + 1);
      current.pop_back();
    }
  }

public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    backtrack(nums, target, 0, 0);
    return result;
  }
};
// @lc code=end
