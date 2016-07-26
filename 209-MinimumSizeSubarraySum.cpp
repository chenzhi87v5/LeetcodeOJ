//Minimum Size Subarray Sum 最短子数组之和    滑动窗口法
/*  
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the 
sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/
/*
这道题给定了我们一个数字，让我们求子数组之和大于等于给定值的最小长度，跟之前那道 Maximum Subarray 最大子数组有些类似，并且
题目中要求我们实现O(n)和O(nlgn)两种解法，那么我们先来看O(n)的解法，我们需要定义两个指针left和right，分别记录子数组的左右的
边界位置，然后我们让right向右移，直到子数组和大于等于给定值或者right达到数组末尾，此时我们更新最短距离，并且将left像右移一
位，然后再sum中减去移去的值，然后重复上面的步骤，直到right到达末尾，且left到达临界位置，即要么到达边界，要么再往右移动，和
就会小于给定值。代码如下： 
*/
//O(n)解法：滑动窗口法，使用两个下标left和right标识窗口（子数组）的左右边界
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int left = 0, right = 0, total = 0, ans = n + 1;
		
		while (right < n) {
			while (right < n && total < s)
				total += nums[right++];
			if (total < s)
				break;
			while (left < right && total >= s)
				total -= nums[left++];
			ans = min(ans, right - left + 1);
		}

		if (ans == n + 1)
			return 0;
		else
			return ans;
	}
};
