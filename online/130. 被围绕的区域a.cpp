#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 被围绕的区域问题可以通过深度优先搜索（DFS）或广度优先搜索（BFS）来解决。以下是一个使用深度优先搜索的C++实现
// dfs 函数用于深度优先搜索，将与边界相连的 'O' 标记为 'A'。
// 然后，遍历整个矩阵，将剩余的 'O' 修改为 'X'，将 'A' 恢复为 'O'
void dfs(vector<vector<char>> &board, int row, int col) {
  int numRows = board.size();
  int numCols = board[0].size();

  if (row < 0 || row >= numRows || col < 0 || col >= numCols ||
      board[row][col] != '0') {
    return;
  }

  // 将当前位置标记为已访问
  board[row][col] = 'A';

  dfs(board, row - 1, col);
  dfs(board, row + 1, col);
  dfs(board, row, col - 1);
  dfs(board, row, col + 1);
}

void solve(vector<vector<char>> &board) {
  int numRows = board.size();
  if (numRows == 0) {
    return;
  }

  int numCols = board[0].size();

  // 对边界上的 'O' 进行深度优先搜索，将与边界相连的 'O' 标记为 'A'
  for (int i = 0; i < numRows; ++i) {
    dfs(board, i, 0);
    dfs(board, i, numCols - 1);
  }

  for (int j = 0; j < numRows; ++j) {
    dfs(board, 0, j);
    dfs(board, numRows - 1, j);
  }

  // 遍历整个矩阵，将剩余的 'O' 修改为 'X'，将 'A' 恢复为 'O'
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (board[i][j] == 'O') {
        board[i][j] = 'X';
      } else if (board[i][j] == 'A') {
        board[i][j] = 'O';
      }
    }
  }
}

// 输出矩阵
void printMatrix(const vector<vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main() {
  // 示例用法
  vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X'}};

  cout << "Original board:" << endl;
  printMatrix(board);

  solve(board);

  cout << "Board after solving:" << endl;
  printMatrix(board);

  return 0;
}
