#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();

    // 判断 s 中是否存在 t 的排列
    bool checkInclusion(std::string t, std::string s) {
        std::unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        for (auto a :need)
        {
            std::cout << "a.fr" << a.first << ",";
            std::cout << "a.se" << a.second << std::endl;
        }

        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size()) {
                char c = s[right];
                right++;
                // 进⾏窗⼝内数据的⼀系列更新
                if (need.count(c)) {
                    window[c]++;
                    if (window[c] == need[c])
                        valid++;
                }
                // 判断左侧窗⼝是否要收缩
                while (right - left >= t.size()) {
                    // 在这⾥判断是否找到了合法的⼦串
                    if (valid == need.size())
                        return true;
                    char d = s[left];
                    left++;
                    // 进⾏窗⼝内数据的⼀系列更新
                    if (need.count(d)) {
                    if (window[d] == need[d])
                        valid--;
                    window[d]--;
                    }
                }
            }
        // 未找到符合条件的⼦串
        return false;
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
    bool is_find = sol.checkInclusion("ab", "eidabooo");
    std::cout << is_find << std::endl;
    return 0;
}