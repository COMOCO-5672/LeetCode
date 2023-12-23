#include <iostream>
#include <vector>

using namespace std;


// 扫描矩阵： 遍历整个矩阵，如果某个元素为0，就在第一行和第一列的对应位置
// 做标记（因为含的行和列都要被置零）。
// 更新矩阵： 遍历第一行和第一列，根据标记，将对应的行和列置零。
// 如果需要，将第一行和第一列置零： 使用两个布尔变量 firstRowZero 和 firstColZero 来检查是否需要将第一行和第一列置零。

void setZeroes(std::vector<std::vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();

  // 标记第一行和第一列是否需要置零
  bool firstRowZero = false;
  bool firstColZero = false;

  // 遍历矩阵，用第一行和第一列来标记需要置零的行和列
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 0) {
        if (i == 0)
          firstRowZero = true;
        if (j == 0)
          firstColZero = true;
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // 根据第一行和第一列的标记，置零对应的行和列
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // 根据第一行和第一列的标记，置零第一行和第一列
  if (firstRowZero) {
    for (int j = 0; j < n; ++j) {
      matrix[0][j] = 0;
    }
  }

  if (firstColZero) {
    for (int i = 0; i < m; ++i) {
      matrix[i][0] = 0;
    }
  }
}

int main() {
  vector<vector<int>> matrix1 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  cout << "Original matrix1:" << endl;
  for (const auto &row : matrix1) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  setZeroes(matrix1);

  cout << "Matrix1 after setZeroes:" << endl;
  for (const auto &row : matrix1) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  vector<vector<int>> matrix2 = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

  cout << "Original matrix2:" << endl;
  for (const auto &row : matrix2) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  setZeroes(matrix2);

  cout << "Matrix2 after setZeroes:" << endl;
  for (const auto &row : matrix2) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
