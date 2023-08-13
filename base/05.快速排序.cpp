#include <iostream>
#include <vector>

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
  quicksort(a, 0, sizeof(a) / sizeof(int));
  for (int i = 0; i <= 8; ++i) {
    std::cout << a[i] << " "; // print => 0 2 4 5 27 34 46 66 95
  }
  std::cout << std::endl;
  return 0;
}
