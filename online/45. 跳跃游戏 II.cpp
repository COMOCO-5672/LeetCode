#include <iostream>
#include <vector>

using namespace std;

int jump(std::vector<int> & nums)
{
    int n = nums.size();
    int step = 0;
    int maxReach = 0;

    int lastJump = 0;

    for (int i = 0; i < n-1;++i)
    {
        maxReach = std::max(maxReach, i + nums[i]);
        if (i == lastJump)
        {
            lastJump = maxReach;
            ++step;
        }
    }

    return step;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = jump(nums);

    cout << "Minimum jumps needed: " << result << endl;

    return 0;
}