#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int trap(std::vector<int> &height) {
  int n = height.size();
  if (n == 0) {
    return 0;
  }

  std::vector<int> leftMax(n, 0);
  std::vector<int> rightMax(n, 0);

  // 计算每个位置左边的最大高度
  leftMax[0] = height[0];
  for (int i = 1; i < n; ++i) {
    leftMax[i] = max(leftMax[i - 1], height[i]);
  }

  // 计算每个位置右边的最大高度
  rightMax[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    rightMax[i] = max(rightMax[i + 1], height[i]);
  }

  // 计算每个位置上能接到的雨水量
  int trappedWater = 0;
  for (int i = 0; i < n; ++i) {
    trappedWater += max(0, min(leftMax[i], rightMax[i]) - height[i]);
  }
  return trappedWater;
}

int main() {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int result = trap(height);
  std::cout << "Trapped, water:" << result << " unite" << std::endl;
  return 0;
}
