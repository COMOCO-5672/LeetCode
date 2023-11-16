// 寻找两个正序数组的中位数
// 什么是中位数， 中位数是一组数据中排在中间位置的数，如果数据量是偶数，则中位数是中间两个数的平均值
// 中位数可以反映一组数据的几种趋势或平局水平。

#include <vector>

class Solution
{
public:
	Solution();
	~Solution();

	double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
	{
		int n = nums1.size() + nums2.size();
		std::vector<int> a(n, 0);

		int i = 0, j = 0, k = 0;
		// 合并两个正序数组
		while (i < nums1.size() && j < nums2.size())
		{
			a[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
		}

		while (i < nums1.size())
		{
			a[k++] = nums1[i++];
		}

		while (j < nums2.size())
		{
			a[k++] = nums2[j++];
		}

		if (n % 2)
			return a[n/2];

		return (a[n/2] + a[n/2 - 1] * 0.5);
	}
	
};

