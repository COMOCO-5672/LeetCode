#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

// 动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        // 交易次数
    int n = prices.size();
    // 保存最大利润
    int dp[2][n + 1];
    // 初始化第一行和第一列
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }

    // 动态规划
    for (int d = 1; d <= n; ++d) {
        for (int i = d; i <= n; ++i) {
            if (d == 1) {
                dp[0][i] = std::max(dp[0][i - 1], prices[i - 1] - prices[i]);
                dp[1][i] = std::max(dp[1][i - 1], prices[i] - prices[i - 1] + dp[0][i - 1]);
            } else {
                dp[0][i] = std::max(dp[0][i - 1], dp[1][i - 1] + prices[i] - prices[i - d]);
                dp[1][i] = std::max(dp[1][i - 1], dp[0][i - d] - prices[i] + prices[i - d]);
            }
        }
    }

    return dp[1][n];

    }
};

int main()
{
    Solution sol;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxProfit = sol.maxProfit(prices);
    std::cout << "max price:" << maxProfit << std::endl;
    return 0;
}
