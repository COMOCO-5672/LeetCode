#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 可以使用哈希表来存储每个数字的索引，当遍历数组时，判断当前数字是否已经在哈希表中，
// 并且其索引与当前索引的差是否不超过 k。
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> numIndexMap;

    for (int i = 0; i < nums.size(); ++i) {
        if (numIndexMap.find(nums[i]) != numIndexMap.end() && i - numIndexMap[nums[i]] <= k) {
            return true;
        }

        numIndexMap[nums[i]] = i;
    }

    return false;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << containsNearbyDuplicate(nums1, k1) << endl;

    vector<int> nums2 = {1, 0, 1, 1};
    int k2 = 1;
    cout << containsNearbyDuplicate(nums2, k2) << endl;

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << containsNearbyDuplicate(nums3, k3) << endl;
    return 0;
}
