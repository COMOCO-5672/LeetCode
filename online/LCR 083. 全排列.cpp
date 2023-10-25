#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
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

public:
    Solution(/* args */);
    ~Solution();

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        dfs(nums, 0);
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
    std::vector<int> nums = { 1,2,3 };
    auto ret = sol.permute(nums);
    return 0;
}

