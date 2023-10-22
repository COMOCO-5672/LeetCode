#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
private:
    
    std::vector<std::vector<int>> path_ret;
    std::vector<int> path;

public:
    Solution(/* args */);
    ~Solution();

    void backTracling(int n ,int k, int sum, int startIndex)
    {
        if(sum > n)
        {
            return;
        }

        if(path.size() == k)
        {
            if(sum == n)
            {
                path_ret.emplace_back(path);
            }
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            std::cout << "i:" << i << std::endl;
            sum +=i;
            path.emplace_back(i);
            backTracling(n,k, sum, i + 1);
            sum -= i;
            path.pop_back();
        }

    }

    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        backTracling(n,k, 0, 1);
        return path_ret;
    }

};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main()
{

    Solution sol;
    sol.combinationSum3(2,4);

    return 1;
}

