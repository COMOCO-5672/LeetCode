/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> ans;
    int nsize = nums.size();
    if (nsize < 3)
      return ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nsize && nums[i] == 0; i++) {
      if (i && nums[i - 1] == nums[i]) {
      }
    }

    return ans;
  }
};
// @lc code=end
