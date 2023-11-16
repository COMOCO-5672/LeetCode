#include <vector>
#include <iostream>
#include <string>

// 最长回文子串
// 使用动态规划来进行完成中心扩散法。更新对应这张表

class Solution
{
public:
	Solution();
	~Solution();

	std::string longestPalindrome2(std::string s)
	{
		std::string v = "";
		std::vector<std::std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));

		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = i; j < s.size(); j++)
			{
				if (i == j)
				{
					dp[i][j] = true;
					if (j - i + 1 > v.size())
						v = s.substr(i, j-i+1);
				}
				else if (s[i] == s[j] && j-i == 1)
				{


				}
				else if ()
				{

				}
			}
		}

	}

	
};


int main()
{



	return 0;
}
