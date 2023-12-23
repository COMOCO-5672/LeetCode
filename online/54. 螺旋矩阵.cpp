#include <iostream>
#include <vector>

using namespace std;

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
  std::vector<int> result;

  if (matrix.empty() || matrix[0].empty()) {
    return result;
  }

  int rows = matrix.size();
  int cols = matrix[0].size();

  int left = 0, right = cols - 1, top = 0, bottom = rows - 1;

  while (left <= right && top <= bottom) {
    for (int i = left; i <= right; ++i) {
      result.emplace_back(matrix[top][i]);
    }
    top++;

    for (int i = top; i <= bottom; ++i) {
      result.emplace_back(matrix[i][right]);
    }
    right--;

    if (top <= bottom) {
      for (int i = right; i >= left; --i) {
        result.emplace_back(matrix[bottom][i]);
      }
      bottom--;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        result.emplace_back(matrix[i][left]);
      }
      left++;
    }
  }
}

int main() {

  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<int> result1 = spiralOrder(matrix1);
  cout << "Spiral order of matrix1: ";
  for (int num : result1) {
    cout << num << " ";
  }
  cout << endl;

  vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  vector<int> result2 = spiralOrder(matrix2);
  cout << "Spiral order of matrix2: ";
  for (int num : result2) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}