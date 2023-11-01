#include <iostream>
#include <vector>

void quicksort(std::vector<int> &nums, int l, int r)
{
    if( l + 1 >= r)
    {
        return;
    }

    int first = l, last = r - 1, key = nums[first];


    while (first < last)
    {
        while (first < last && nums[last] >= key)
        {
            last--;
        }

        nums[first] = nums[last];

        while (first < last && nums[first] < key)
        {
            first++;
        }
        
        nums[last] = nums[first];
    }
    
    quicksort(nums, 1, first);
    quicksort(nums, first + 1, r);

}



