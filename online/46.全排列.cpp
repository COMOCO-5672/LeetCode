/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    void dfs(vector<int> nums, int x)
    {
        if (x == nums.size() - 1)
        {
            res.emplace_back(nums);
            return;
        }

        for (int i = x; i < nums.size(); i++)
        {
            swap(nums[i], nums[x]);
            dfs(nums, x+1);
            swap(nums[i], nums[x]);
        }

    }
};

#if 1 
int main()
{
    Solution sol;
    vector<int> num = {1, 2, 3};
    auto list = sol.permute(num);
    for (int i = 0; i < list.size() ; i++)
    {
        int len  = list.at(i).size();
        cout << "[";
        for (int j = 0; j < len ;j++)
        {
            cout << list.at(i).at(j);
            if (j != len - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
#endif

// @lc code=end

