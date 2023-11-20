#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> map;
        int standard = nums.size() / 2;
        for (int i =0; i < nums.size(); i++)
        {
            auto find_item = map.find(nums.at(i));
            if (find_item != map.end())
            {
                map[nums.at(i)]++;
                if (map[nums.at(i)] > standard)
                {
                    return nums.at(i);
                }
            }else {
                    map.insert(std::pair(nums.at(i), 1));
                }
        }
        return nums.at(nums.size() - 1);
    }
};