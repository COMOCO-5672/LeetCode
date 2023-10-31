#include <iostream>
#include <vector>


int search_binary(std::vector<int> vec, int target)
{
    int low = 0;
    int high = vec.size() - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {
        if(vec[mid] == target) {
            return mid;
        } else if(target < vec[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return -1;
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5};
    int ret = search_binary(vec, 3);
    std::cout << " ret:" << ret << std::endl;
    return 0;
}


