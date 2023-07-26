#include <iostream>
#include <vector>

int search_binary(std::vector<int> vec, int target) {
  int low = 0;
  int high = vec.size() - 1;
  int mid = (low + high) / 2;

  while (low <= high) {
    if (vec[mid] == target) {
      return mid;
    } else if (target < vec[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }
  return low++;
}

int main() {
  std::vector<int> a = {1, 3, 5, 6};
  auto idx = search_binary(a, 2);
  std::cout << "a" << idx << std::endl;
  return 0;
}