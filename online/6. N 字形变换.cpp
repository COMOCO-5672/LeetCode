
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string convert(std::string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size()) {
        return s;
    }

    std::vector <std::string> rows(numRows);

    int curRow = 0;
    bool goingDown = false;

    for (char c: s) {
        rows[curRow] += c;
        // 当位于第一行或者最后一行，需要掉头进行排列
        if (curRow == 0 || curRow == numRows - 1) {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    std::string result;
    for (const std::string &row: rows) {
        result += row;
    }

    return result;
}

int main()
{
    string input = "PAYPALISHIRING";
    int numRows = 3;
    string result = convert(input, numRows);

    cout << "Converted string: " << result << endl;
    return 0;
}
