//
// Created by Administrator on 2023/12/23.
//

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
    int len = s.size();
    int i = 0;

    while (i < len) {
        // 大写英文字母
        if (s[i] >= 'A' && s[i] <= 'Z') {
            // 总共有32的英文字母
            s[i] += 32;
            ++i;
            continue;
        }

        if ((s[i] >= 'a' && s[i] <= 'z') || isdigit(s[i])) {
            ++i;
            continue;
        }

        // 擦除其他字符
        s.erase(s.begin() + i);
        --len;
    }

    int l = 0, r = len - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            ++l;
            --r;
            continue;
        }
        return false;
    }
    return true;

}

int main()
{
    std::string str = "A man, a plan, a canal: Panama";
    auto ret =  isPalindrome(str);
    std::cout << "return :" << ret << std::endl;
    return 0;
}
