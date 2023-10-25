#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution(/* args */);
    ~Solution();

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

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        dfs(nums, 0);
        return path_ret;
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

