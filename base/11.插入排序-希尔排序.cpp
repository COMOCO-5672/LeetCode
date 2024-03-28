#include <iostream>

using namespace std;

void ShellSort(int *arr, int len) {
  int grp = len / 2; // 计算增量

  for (; grp > 0; grp = grp / 2) { // 每次计算完一轮，增量再除以二

    // 选择排序
    for (int i = grp; i < len; i++) {
      int cur = arr[i]; // 先空出第二个数的位置
      int j = 0;

      // 根据增量往前比较，小的在前，大的在后
      for (j = i - grp; j >= 0 && arr[j] > cur; j = j - grp) {
        arr[j + grp] = arr[j]; // 符合条件将前面的数据移动到空出的位置
      }
      arr[j + grp] = cur; // 最后将待插入数据cur插入到前面空出的位置
    }
  }
}

int main() {
  int arr[]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int len = sizeof(arr) / sizeof(arr[0]);

  ShellSort(arr, len);

  for (int i = 0; i < len; i++) {
    cout << *(arr + i) << ", ";
  }
  cout << endl;

  system("pause");
  return 0;
}