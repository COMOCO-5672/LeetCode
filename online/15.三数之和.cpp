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

    for (int i = 0; i < nsize && nums[i] <= 0; i++) {
      if (i && nums[i - 1] == nums[i])
        continue;
      int l = i + 1, r = nums.size() - 1;
      int target = 0 - nums[i];
      while (l < r) {
        if (nums[l] + nums[r] < target)
          l++;
        else if (nums[l] + nums[r] > target)
          r--;
        else {
          std::vector<int> ians = {nums[i], nums[l], nums[r]};
          ans.push_back(ians);
          l++;
          r--;
          while (l < r && nums[l - 1] == nums[l])
            l++;
          while (l < r && nums[r + 1] == nums[r])
            r--;
        }
      }
    }

    return ans;
  }
};
// @lc code=end
