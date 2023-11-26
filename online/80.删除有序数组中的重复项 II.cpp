#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int length = nums.size();
        if (length <= 2)
        {
            return length;
        }

        int slow = 2;
        for (int fast = 2; fast < length; ++fast)
        {
            if (nums[fast] != nums[slow -2])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
        }

        return slow;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int result = sol.removeDuplicates(nums);
    for (int i = 0; i < result; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
