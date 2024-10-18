#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);
    for (int i = 1; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        row[j] += row[j - 1];
        //std::cout << row[j] << " ";
      }
      //std::cout << std::endl;
    }
    return row;
  }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    sol.getRow(10);
    return 0;
}
