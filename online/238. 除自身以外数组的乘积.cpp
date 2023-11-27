#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> output(n, 1);

        int leftProduct = 1;
        for (int i = 0; i < n; ++i)
        {
            output[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0;--i)
        {
            output[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return output;
    }
};


int main()
{
    Solution sol;
    std::vector<int> num = {1, 2, 3, 4};
    std::vector<int> result = sol.productExceptSelf(num);

    cout << "Output array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

