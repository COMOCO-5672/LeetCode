#include <iostream>

// 从头开始，拿当前值跟之前的数据进行比对，当遇到比自己小的数停下来

// 时间复杂度O(n^2)
// 空间福再度O(1)
void insertsort(int a[], int n) {
  for (int i = 0; i < n; i++) {
      // 先正向
      std::cout << "i_index:" << i << "\r\n";
    for (int j = i; j - 1 >= 0; j--) {
      std::cout << "   index:j-1:" << j - 1 << "\r\n";
      // 如果满足条件就逆向
      if (a[j] < a[j - 1]) {
        std::swap(a[j], a[j - 1]);
      } else {
        break;
      }
    }
  }
}

int main() {
  int a[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
  insertsort(a, 10);

  for (int k = 0; k < 10; k++) {
    std::cout << a[k] << "  ";
  }
}
