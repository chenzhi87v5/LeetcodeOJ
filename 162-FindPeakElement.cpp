//Find Peak Element 求数组的峰值
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

//二分法 
/*
这道题是求数组的一个峰值，这个峰值可以是局部的最大值，这里用遍历整个数组找最大值肯定会出现Time Limit Exceeded，我们要考虑使用类似于二分查找法来缩短时间，由于只是需要找到任意一个峰值，那么我们在确定二分查找折半后中间那个元素后，和紧跟的那个元素比较下大小，如果大于，则说明峰值在前面，如果小于则在后面。这样就可以找到一个峰值了，代码如下：
*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[mid + 1]) left = mid + 1;
			else right = mid;
		}
		return right;
	}
};
