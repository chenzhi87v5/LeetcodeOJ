/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

//1-:从后开始向前合并
//时间复杂度m + n, 空间复杂度 1

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ia = m - 1, ib = n - 1, icur = m + n - 1;

		while (ia >= 0 && ib >= 0) {
			nums1[icur--] = nums1[ia] > nums2[ib] ? nums1[ia--] : nums2[ib--]; //合并
		}

		while (ib >= 0) { 	//数组nums2 还有元素没和合并到nums1
			nums1[icur--] = nums2[ib--];
		}
	}
};
