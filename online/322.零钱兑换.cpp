#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            for (int coin: coins)
            {
                if(i - coin < 0)
                {
                    continue;
                }
                cout << endl;
                cout << "[i]:" << i << ", coin:" << coin ;
                cout << " dp[i]:" << dp[i] << ", 1 + dp[i - coin]:" << 1 + dp[i - coin] <<endl;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
                cout << endl;
                for (int j = 0; j < dp.size(); j++)
                {
                    cout << "dp[" << j << "]:" << dp[j] << ", ";
                }
                cout << endl;
            }
        }
        return (dp[amount] == amount + 1 ? -1 : dp[amount]);
    }
};


int main()
{
    Solution sol;
    vector<int> a = {1,2,5};
    int amount = 11;
    auto ret = sol.coinChange(a, amount);

    cout << "ret" << ret << endl;
    return 0;
}
