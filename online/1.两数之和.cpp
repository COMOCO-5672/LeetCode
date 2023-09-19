/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>  map;
        vector<int> ret;
        for (int i =0; i < nums.size(); i++)
        {
            auto it = map.find(target - nums[i]);
            if(it != map.end())
            {
                ret.push_back(it->second);
                ret.push_back(i);
                break;
            }
            else {
                map.insert({nums[i], i});
            }
        }
        return ret;
    }
};

#if 0
int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    int target = 3;
    Solution sol;
    auto ret = sol.twoSum(nums, target);
    for (auto &it: ret)
    {
        cout << it << endl;
    }
    return 0;
}
#endif
// @lc code=end

