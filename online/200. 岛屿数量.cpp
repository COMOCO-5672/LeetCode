#include <iostream>
#include <string>
#include <vector>

// 岛屿数量问题可以通过深度优先搜索（DFS）或广度优先搜索（BFS）来解决
using namespace std;

void dfs(vector<vector<char>> &grid, int row, int col) {
  int numRows = grid.size();
  int numCols = grid[0].size();

  if (row < 0 || row >= numRows || col < 0 || col >= numCols ||
      grid[row][col] == '0') {
    return;
  }

  // 当前岛屿标记为已访问
  grid[row][col] = '0';

  dfs(grid, row - 1, col);
  dfs(grid, row + 1, col);
  dfs(grid, row, col - 1);
  dfs(grid, row, col + 1);
}

int numIsLands(vector<vector<char>> &grid) {
  int numRows = grid.size();

  if (numRows == 0) {
    return 0;
  }

  int numCols = grid[0].size();
  int islandCount = 0;

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (grid[i][j] == '1') {
        dfs(grid, i, j);
        ++islandCount;
      }
    }
  }

  return islandCount;
}

int main() {
  // 示例用法
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};

  int islands = numIsLands(grid);

  cout << "Number of islands: " << islands << endl;
  return 0;
}
