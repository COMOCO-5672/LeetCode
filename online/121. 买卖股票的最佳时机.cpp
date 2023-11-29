#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    int maxProfit(std::vector<int> prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        int min_price = prices[0];
        int max_price = 0;

        for (int price: prices)
        {
            max_price = std::max(max_price, price - min_price);
            min_price = std::min(min_price, price);
        }
        return max_price;
    }

};