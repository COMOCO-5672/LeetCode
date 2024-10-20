/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start

#include <vector>
class Solution {
public:
    int climbStairs(int n) {
        // 第一类解法
        // int i;
        // int f[46] = {1,1};
        // for (int i = 2;i <= n;++i) {
        //     f[i] = f[i-1]+f[i-2];
        // }
        // return f[n];

        //一样的
        // if(n<=2) return n;
        // vector<int> dp(n+1,1);
        // for(int i = 2;i<=n;++i)
        // {
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        // 第二类解法
        if(n<2) return n;
        int pre2 =1,pre1 =2, cur;
        for(int i = 2;i <n;++i)
        {
            cur = pre1+pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
// @lc code=end

