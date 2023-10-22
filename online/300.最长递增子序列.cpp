#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    int lengthOfLTS(std::vector<int>& nums)
    {
        // dp存的是当前有多个个增长的子序列，从头开始计算，下一个是上一个的数+1
        std::vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j)
                if (nums[i] > nums[j])
                    dp[i] = std::max(dp[i], dp[j] + 1);
        }

        // 遍历一遍，获取最大的那个值
        int res = 0;
        for (int i = 0; i < dp.size(); ++i)
            res = std::max(res, dp[i]);
        
        return res;
    }

};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main()
{
    Solution sol;


    return 0;
}