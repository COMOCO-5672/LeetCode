#include <iostream>
// 时间复杂度O(n^2)
// 空间复杂度O(1)

// 冒泡排序是找到最大(最小)的冒泡到后面
void bubblesort(int list[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (list[j] > list[j + 1]) {
        std::swap(list[j + 1], list[j]);
      }
    }
  }
}

int main() {
  int a[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
  bubblesort(a, 10);

  for (int k = 0; k < 10; k++) {
    std::cout << a[k] << "  ";
  }

  return 0;
}
