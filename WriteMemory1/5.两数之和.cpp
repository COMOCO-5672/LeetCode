#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twosum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;
        std::vector<int> ret;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                ret.push_back(it->second);
                ret.push_back(i);
                break;
            }
            else {
                map.insert({nums[i] , i});
            }
        }
        return ret;
    }
};

