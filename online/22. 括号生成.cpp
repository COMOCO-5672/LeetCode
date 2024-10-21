#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    vector<string> result;

    void backtrack(string &current, int open, int close, int n)
    {
        if (current.length() == n * 2)
        {
            result.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            backtrack(current, open + 1, close, n);
            current.pop_back();
        }

        if (close < open)
        {
            current.push_back(')');
            backtrack(current, open, close + 1, n);
            current.pop_back();
        }
    }

     vector<string> generateParenthesis(int n) {
        string current;
        backtrack(current, 0, 0, n);
        return result;
    }

    void dfs(std::vector<std::string> &ans, std::string cur, int left, int right, int n)
    {
        if (left == n && right == n) {
            ans.emplace_back(cur);
            return;
        }

        if (left < right) {
            return;
        }

        if (left < n) {
            std::cout << "left:" << left << std::endl;
            dfs(ans, cur + '(', left + 1, right, n);
        }

        if (right < n) {
            std::cout << "right:" << right << std::endl;
            dfs(ans, cur + ')', left, right + 1, n);
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";

        if (n == 0) {
            return result;
        }

        dfs(result, current, 0, 0, n);
        return result;
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
    int n = 3;
    std::vector<std::string> res;
    Solution s;
    res = s.generateParenthesis(n);
    for (auto s : res)
        std::cout << s << std::endl;

    return 0;
}



