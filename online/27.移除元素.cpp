/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start

#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int> &nums, int val) {
    nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
  }
};
// @lc code=end
