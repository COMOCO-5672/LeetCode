#include <iostream>

// 时间复杂度O(n^2)
// 空间复杂度O(1)

// 选择排序是比较出最大(最小)的放在最前面
void selectsort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        std::swap(a[i], a[j]);
      }
    }
  }
}

int main() {
  int a[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
  selectsort(a, 10);

  for (int k = 0; k < 10; k++) {
    std::cout << a[k] << "  ";
  }
  return 0;
}