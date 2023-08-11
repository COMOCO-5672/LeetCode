#include <iostream>

// 从头开始，拿当前值跟之前的数据进行比对，当遇到比自己小的数停下来

void insertsort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j - 1 >= 0; j--) {
      std::cout << "index:" << j - 1 << "\r\n";
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
