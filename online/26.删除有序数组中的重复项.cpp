/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {

        int index = 1;
        int length  = nums.size();

        for (int i = 1; i < length; ++i)
        {
            if(nums[i] != nums[i-1])
            {
                nums[index] = nums[i];
                ++index;
            }
        }

        return index;

    }
};
// @lc code=end

