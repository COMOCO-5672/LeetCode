#include <iostream>

// 归并排序就是将数组分成两部分
// 双指针位置比较，根据大小值将数据存入临时数组中

void mergeCount(int a[], int L, int mid, int R) {
  int *tmp = new int[L + mid + R];
  int i = L;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= R) {
    if (a[i] < a[j])
      tmp[k++] = a[i++];
    else
      tmp[k++] = a[j++];
  }

  while (i <= mid)
    tmp[k++] = a[i++];
  while (j <= R)
    tmp[k++] = a[j++];
  for (int p = 0; p < k; ++p)
    a[L + p] = tmp[p];
  delete tmp;
}
void mergeSort(int a[], int L, int R) {
  if (L >= R) {
    return;
  }
  int mid = L + (R - L) / 2;
  mergeSort(a, L, mid);
  mergeSort(a, mid + 1, R);
  mergeCount(a, L, mid, R);
}
int main() {
  int a[] = {0, 34, 66, 2, 5, 95, 4, 46, 27};
  mergeSort(a, 0, sizeof(a) / sizeof(int));
  for (int i = 0; i <= 8; ++i) {
    std::cout << a[i] << " "; // print => 0 2 4 5 27 34 46 66 95
  }
  std::cout << std::endl;
  return 0;
}