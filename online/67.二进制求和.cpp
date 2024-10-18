/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {

#if 0

        int len1= a.size();
        int len2 = b.size();
        int len = (len1 > len2) ?len1:len2;
        char* ret = (char*)malloc(sizeof(char) * (len + 2));

        int remain = 0;
        int i = len1 - 1;
        int j = len2 - 1;

        int k = len + 1;
        ret[k--] = '\0';

        while (i>=0 || j>=0 || remain >0)
        {
            remain += (i >= 0) ? a[i--] - '0' : 0;
            remain += (j >= 0) ? b[j--] - '0' : 0;
            
            ret[k--] = remain % 2 + '0';
            remain /= 2;
        }

        return ret + k + 1;
#endif
    std::string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
      int sum = carry;
      if (i >= 0)
        sum += a[i--] - '0';
      if (j >= 0)
        sum += b[j--] - '0';
      result = char(sum % 2 + '0') + result;
      carry = sum / 2;
    }

    return result;
  }
};
// @lc code=end
