//
// Created by COMOCO on 3/26/2024.
//

#include <vector>

using namespace std;

void shellSort(std::vector<int>& arr)
{
    int n = arr.size();

    // 定义希尔排序的间隔序列
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个间隔进行插入排序
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            // 在当前间隔内进行插入排序
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
