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

    int change(int amount, std::vector<int>& coins) {
        std::vector<int> dp(amount, 0);
        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if(j - coins[i] >= 0)
                {
                    dp[j] = dp[j] + dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
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
    return 0;
}