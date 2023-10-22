#include <iostream>
#include <vector>

class Solution
{
private:
    
    std::vector<std::vector<int>> path_ret;
    std::vector<int> path;

public:
    Solution(/* args */);
    ~Solution();

    void backTracling(int n ,int k, int startIndex)
    {
        if(path.size() == k)
        {
            path_ret.emplace_back(path);
            for (int i = 0; i< path.size(); ++i)
            {
                std::cout << path[i] << ",";
            }
            std::cout << std::endl;
            return;
        }

        for (int i = startIndex; i <= n - ( k - path.size()) + 1; i++)
        {
            std::cout << "i:" << i << std::endl;
            path.emplace_back(i);
            backTracling(n,k,i + 1);
            path.pop_back();
        }

    }

    std::vector<std::vector<int>> combine(int n, int k) {
        backTracling(n,k,1);
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
    sol.combine(4,4);

    return 1;
}

