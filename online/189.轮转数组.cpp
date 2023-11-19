
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = nums.size();
        if (k > numsSize)
        {
            k %= numsSize;
        }
        int *tmp = (int*) malloc(sizeof(int) * numsSize);

        memcpy(tmp, &nums + numsSize - k, sizeof(int) * k);
        memcpy(tmp + k, &nums, sizeof(int) * (numsSize - k));
        memcpy(&nums, tmp, sizeof(int) * numsSize);
        free(tmp);
        tmp = NULL;
    }
};


int main()
{
    Solution sol;
    std::vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums, k);
    for (auto num : nums)
    {
        std::cout << num << std::endl;
    }
    return 0;
}