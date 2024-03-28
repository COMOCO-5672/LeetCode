#include <iostream>
#include <vector>

// 取一个数，将大于他的数放右边，小于他的数放左边

void quicksort2(std::vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int i,j,x;

        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while(i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quicksort2(a, l, i-1); /* 递归调用 */
        quicksort2(a, i+1, r); /* 递归调用 */
    }
}

void quicksort(std::vector<int> &nums, int l, int r) {
  if (l + 1 >= r) {
    return;
  }
  int first = l, last = r - 1, key = nums[first];
  while (first < last) {
    while (first < last && nums[last] >= key) {
      last--;
    }

    nums[first] = nums[last];

    while (first < last && nums[first] < key) {
      first++;
    }

    nums[last] = nums[first];
  }

  nums[first] = key;

  quicksort(nums, 1, first);
  quicksort(nums, first + 1, r);
}

int main() {
  std::vector<int> a = {0, 34, 66, 2, 5, 95, 4, 46, 27};
  quicksort2(a, 0, a.size());
  for (int i = 0; i <= a.size() - 1; ++i) {
    std::cout << a[i] << " "; // print => 0 2 4 5 27 34 46 66 95
  }
  std::cout << std::endl;
  return 0;
}
