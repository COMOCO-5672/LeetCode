/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1);
        f[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            int w = nums[i - 1];
            f[i] = max(f[i-1], f[i-2] + w);
        }
        return f[n];
    }
};
// @lc code=end

