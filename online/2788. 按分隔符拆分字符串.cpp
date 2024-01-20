//
// Created by COMOCO on 1/20/2024.
//
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector <string> splitWordsBySeparator(vector <string> &words, char separator)
    {
        vector <string> ret;
        std::string tmp_str;
        for (int i = 0; i < words.size(); ++i) {
            string word = words.at(i);
            int size = word.size();
            for (int j = 0; j < size; ++j) {
                if (word[j] == separator) {
                    if (!tmp_str.empty()) {
                        ret.emplace_back(tmp_str);
                        tmp_str = "";
                    }
                }
                else {
                    tmp_str.push_back(word[j]);
                }

                if (j == size - 1) {
                    if (!tmp_str.empty()) {
                        ret.emplace_back(tmp_str);
                        tmp_str = "";
                    }
                }
            }
        }
        return ret;
    }