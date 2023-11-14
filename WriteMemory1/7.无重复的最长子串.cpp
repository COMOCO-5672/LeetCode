#include <algorithm>
#include <string>
#include <set>

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

//解法：滑动窗口

class Solution {
    public:
    int lengthOfLongestSubString(std::string s)
    {
        if(s.empty())
        {
            return 0;
        }

        int start = 0, end = 1;
        int ret = 1;
        std::set<char> a;

        a.insert(s[start]);

        while (end < s.length())
        {
            if (a.find(s[end]) !=  a.end()){
                a.erase(s[start++]);
            } else {
                a.insert(s[end++]);
                ret = std::max(ret , end-start);
            }
        }
        return ret;
    }
};

int main ()
{

    return 0;
}