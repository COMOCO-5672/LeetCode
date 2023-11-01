#include <iostream>

void insertsort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j - 1 >= 0; j--)
        {
            if(a[j] < a[j - 1])
            {
                std::swap(a[j], a[j - 1]);
            }
            else {
                break;
            }
        }
    }
}

int main()
{
    int a[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
}