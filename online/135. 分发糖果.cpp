#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        const int len = ratings.size();
        if (len < 2) {
            return len;
        }

        std::vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i)
        {
            if (ratings[i] > ratings[i-1])
            {
                dp[i] = dp[i-1]+1;
            }
        }

        for (int i = len - 1;i > 0; --i)
        {
            if (ratings[i-1] > ratings[i])
            {
                dp[i-1] = std::max(dp[i-1], dp[i] +1);
            }
        }

       return accumulate(dp.begin(),dp.end(),0);

    }
};

int main()
{
    return 0;
}
