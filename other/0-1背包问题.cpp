#include <iostream>
#include <vector>
#include <algorithm>

int maxValue()
{
    int N = 3;
    int W = 4;
    std::vector<int> weights = {2, 1, 3};
    std::vector<int> vals = {4, 2, 3};

    std::vector<std::vector<int>> dp(N+1, std::vector<int>(W+1, 0));

    for (int j = 1; j <= N; ++j)
    {
        for (int i = 1; i <= W; ++i)
        {
            if (i - weights[j - 1] < 0)
            {
                dp[j][i] = dp[j-1][i];
            }
            else {
                dp[j][i] = std::max(dp[j - 1][i - weights[j-1]] + vals[j - 1], dp[j -1][i]);
            }
        }
    }
    return dp[N][W];
}


int main()
{
    std::cout << maxValue() << std::endl;
    return 0;
}