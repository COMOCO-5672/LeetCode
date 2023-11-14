#include <iostream>
#include <vector>
#include <unordered_map>

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
// 你可以按任意顺序返回答案。

// 解法：循环测试两个数的差，然后查看是否有改值并且已经添加到map中, 如果有查找结束，如果没有就继续直到结束

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

