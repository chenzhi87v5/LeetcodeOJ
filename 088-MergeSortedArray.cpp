//Merge Sorted Array 混合插入有序数组
/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

//从后开始向前合并  关键点
//时间复杂度m + n, 空间复杂度 1
/*
算法思想是：由于合并后A数组的大小必定是m+n，所以从最后面开始往前赋值，先比较A和B中最后一个元素的大小，把较大的那个插入到
m+n-1的位置上，再依次向前推。如果A中所有的元素都比B小，那么前m个还是A原来的内容，没有改变。如果A中的数组比B大的，当A循环完
了，B中还有元素没加入A，直接用个循环把B中所有的元素覆盖到A剩下的位置。代码如下: 
*/
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
