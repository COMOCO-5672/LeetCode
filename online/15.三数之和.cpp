/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1, right = n - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          result.emplace_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) {
            left++;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }
          left++;
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }
    return result;

#if 0

    std::vector<std::vector<int>> ans;
    int nsize = nums.size();
    if (nsize < 3)
      return ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nsize && nums[i] <= 0; i++) {
      if (i && i >= 1 && nums[i - 1] == nums[i])
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
#endif
  }
};

// int main() {
//   Solution so;
//   std::vector<int> m = {-1, 0, 1, 2, -1, -4};
//   auto sum_tree = so.threeSum(m);
//   for (auto &it : sum_tree) {
//     std::cout << *it << "\r\n" < std::endl;
//   }
//   return 0;
// }

// @lc code=end
