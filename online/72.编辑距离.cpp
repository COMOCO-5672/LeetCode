#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    int minDistence(std::string word1, std::string word2)
    {
        int m = word1.size(), n = word2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <=m; ++i)
        {
            dp[i][0] = i;
        }

        std::cout << "size1:" << dp.size();
        std::cout << "size2:" << dp[0].size() << std::endl;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = std::min(std::min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1])+ 1;
                }
            }

            for (int c = 1; c <= n ; ++c)
            {
                std::cout << " " << dp[m][c] << ", ";
            }
            std::cout << std::endl;

        }
        return dp[m][n];
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
    auto ret = sol.minDistence("red", "apple");
    std::cout << ret << std::endl;
    return 0;
}