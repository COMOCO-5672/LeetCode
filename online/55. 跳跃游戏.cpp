#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(std::vector<int> &nums)
{
    int n = nums.size();
    int maxReach = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i > maxReach)
        {
            return false;
        }

        maxReach = std::max(maxReach, i + nums[i]);
        if (maxReach >= n - 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    bool ret = canJump(nums);
    std::cout << (ret ? "Can jump to the end" : "Cannot jump to the end") << std::endl;
    return 0;
}
