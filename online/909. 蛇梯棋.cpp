#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 蛇梯棋问题可以通过广度优先搜索（BFS）来解决

int snakesAndLadders(vector<vector<int>> &board) {
  int n = board.size();
  vector<int> flattendBoard(n * n);

  // 将二维期盼转换为一维坐标
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; ++j) {
        flattendBoard[i * n + j] = board[n - 1 - i][j];
      }
    } else {
      for (int j = 0; j < n; ++j) {
        flattendBoard[i * n + j] = board[n - 1 - i][n - 1 - j];
      }
    }
  }

  // BFS
  queue<int> q;
  vector<int> distance(n * n, -1);

  q.push(0);
  distance[0] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for (int i = 1; i <= 6; ++i) {
      int next = current + i;
      if (next >= n * n) {
        break;
      }

      // 获取下一个位置（考虑蛇和梯子的影响）
      int dest = (flattendBoard[next] == -1) ? next : flattendBoard[next] - 1;
      if (distance[dest] == -1) {
        distance[dest] = distance[current] + 1;
        q.push(dest);
      }

      if (dest == n * n - 1) {
        return distance[dest];
      }
    }
  }
  return -1;
}

int main() {
  // 示例用法
  vector<vector<int>> board = {
      {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  int result = snakesAndLadders(board);
  cout << "Minimum number of moves: " << result << endl;
  return 0;
}
