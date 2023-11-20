
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

        memcpy(tmp, &nums[0] + numsSize - k, sizeof(int) * k);
        memcpy(tmp + k, &nums[0], sizeof(int) * (numsSize - k));
        memcpy(&nums[0], tmp, sizeof(int) * numsSize);
        free(tmp);
        tmp = NULL;
    }

    // 第二种， 时间复杂度o(1)
    void rotate2(vector<int>& nums, int k)
    {
        int n = nums.size();
        k %= n;
        k = n - k;
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};


int main()
{
    Solution sol;
    std::vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums, k);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums.at(i) << std::endl;
    }

    return 0;
}