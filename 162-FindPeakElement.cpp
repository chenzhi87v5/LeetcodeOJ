/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/

/*
寻找峰值元素index 时间复杂度要求logn 
注意边界检测
*/

//法一:顺序查找，不满足时间复杂度
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//边界检测
		int n = nums.size();
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		if (nums[0] > nums[1])
			return 0;
		if (nums[n - 1] > nums[n - 2])
			return n - 1;
		//顺序法
		for (int i = 1; i < n - 1; i++)
			if (nums[i] > nums[i -1] && nums[i] > nums[i + 1])
				return i;

		return -1;
	}
};

//法二：二分法（递归 OR 迭代）
//迭代二分法
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		//边界检测
		int n = nums.size();
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		if (nums[0] > nums[1])
			return 0;
		if (nums[n - 1] > nums[n - 2])
			return n - 1;
		//二分法
		int l = 1, r = nums.size();
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
				return mid;
			if (nums[mid] > nums[mid - 1])
				l = mid + 1;
			else
				r = mid - 1;
		}

		return -1;
	}
};
