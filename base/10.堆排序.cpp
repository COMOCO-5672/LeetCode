#include <string>
#include <vector>
#include <iostream>

void max_heap(int a[], int start, int end)
{
    int c = start;
    int l = 2 * c + 1;
    int tmp = a[c];

    for (; l <= end; c=l, l=2*l+1) {
        if (l < end && a[l] < a[l+1])
            l++;

        if (tmp >= a[l])
            break;
        else {
            a[c] = a[l];
            a[l] = tmp;
        }
    }
}

void heap_sort_asc(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        max_heap(a, i, n-1);
    }

    for (i = n - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        max_heap(a, 0, i-1);
    }
}

int main()
{
    int a[] = {10, 9, 12, 24, 7, 8, 18};
    heap_sort_asc(a, 7);
    for (auto v : a) {
        std::cout << "index:" << v << std::endl;
    }
    return 0;
}
