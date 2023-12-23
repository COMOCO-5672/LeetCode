#include <iostream>
#include <vector>

using namespace std;

// 遍历整个矩阵，计算每个细胞周围的存活邻居数量。这可以通过遍历细胞周围的8个方向（水平、垂直、对角线）来实现。

// 根据规则更新每个细胞的状态。为了能够在原地修改，我们使用额外的状态来表示下一步的状态，如下：

// 0 表示当前是死细胞，下一步还是死细胞。
// 1 表示当前是活细胞，下一步还是活细胞。
// 2 表示当前是活细胞，下一步会变成死细胞。
// 3 表示当前是死细胞，下一步会变成活细胞。
// 遍历整个矩阵，将2和3还原成0和1。

// 这样，就在原地完成了生命游戏的模拟。

void gameOfLife(std::vector<std::vector<int>> &board) {
  int m = board.size();
  int n = board[0].size();

  std::vector<int> dirs = {-1, 0, 1};

  // 遍历整个矩阵
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int liveNeighbors = 0;

      // 遍历当前细胞周围的8个相邻四包
      for (int x : dirs) {
        for (int y : dirs) {
          if (x == 0 && y == 0) {
            continue; // 跳过当前细胞
          }

          // 计算相邻细胞的坐标
          int ni = i + x;
          int nj = j + y;

          // 检查相邻细胞的状态
          if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
              (board[ni][nj] == 1 || board[ni][nj] == 2)) {
            liveNeighbors++;
          }
        }
      }

      // 根据规则更新细胞的状态
      if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
        board[i][j] = 2;
      } else if (board[i][j] == 0 && liveNeighbors == 3) {
        board[i][j] = 3;
      }
    }
  }

  // 将2和3还原成0和1
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == 2) {
        board[i][j] = 0;
      } else if (board[i][j] == 3) {
        board[i][j] = 1;
      }
    }
  }
}

int main() {
  // 示例用法
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

  cout << "原始矩阵：" << endl;
  for (const auto &row : board) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  gameOfLife(board);

  cout << "更新后的矩阵：" << endl;
  for (const auto &row : board) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
