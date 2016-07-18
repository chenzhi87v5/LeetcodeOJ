//Kth Largest Element in an Array 数组中第k大的数字
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
//法一:优先队列 时间 O(NlogK) 空间 O(K) 遍历数组时将数字加入优先队列（堆），一旦堆的大小大于k就将堆顶元素去除，确保堆的大小为k。遍历完后堆顶就是返回值。

//法二:排序法 时间 O(NlogN) 空间 O(1)
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};
