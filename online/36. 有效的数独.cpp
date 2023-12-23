
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  std::unordered_set<std::string> seen;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      char currChar = board[i][j];
      if (currChar != '.') {
        // 检查行
        std::string rowKey = currChar + " in row " + to_string(i);
        if (seen.find(rowKey) != seen.end()) {
          return false;
        }
        seen.insert(rowKey);

        // 检查列
        std::string colKey = currChar + " in col " + to_string(j);
        if (seen.find(colKey) != seen.end()) {
          return false;
        }
        seen.insert(colKey);

        // 检查3x3宫
        std::string boxkey = currChar + " in box " + to_string(i / 3);
        if (seen.find(boxkey) != seen.end()) {
          return false;
        }
        seen.insert(boxkey);
      }
    }
  }
  return true;
}

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  bool result = isValidSudoku(board);

  cout << "Is the Sudoku valid? " << boolalpha << result << endl;
  return 0;
}
