//House Robber II 打家劫舍之二
/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not 
get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous 
street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of 
money you can rob tonight without alerting the police.
*/

//198. House Robber扩展 街道为直线 此题街道是一个圆
/*
这道题是之前那道House Robber 打家劫舍的拓展，现在房子排成了一个圆圈，则如果抢了第一家，就不能抢最后一家，因为首尾相连了，
所以第一家和最后一家只能抢其中的一家，或者都不抢，那我们这里变通一下，如果我们把第一家和最后一家分别去掉，各算一遍能抢的最
大值，然后比较两个值取其中较大的一个即为所求。那我们只需参考之前的House Robber 打家劫舍中的解题方法，然后调用两边取较大值
，代码如下： 
*/
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
		return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
	}

	int rob(vector<int> &nums, int left, int right) {
		if (right - left <= 1) return nums[left];
		vector<int> dp(right, 0);
		dp[left] = nums[left];
		dp[left + 1] = max(nums[left], nums[left + 1]);
		
		for (int i = left + 2; i < right; ++i) {
			dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
		}
		return dp.back();
	}
};
