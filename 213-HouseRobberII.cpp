/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

//198. House Robber扩展
//198 街道为直线 213 街道是一个圆

class Solution {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		
		//参数检查
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];
		
		vector<int> dp(n);
		/*取值从1...(n-1)，由于是圆 (n - 1)与0接壤 故舍弃num[0]*/
		dp[0] = 0;
		dp[1] = nums[1];
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		
		int answer = dp[n - 1];

		/*取值从0...(n-2)，由于是圆 (n - 1)与0接壤 故舍弃num[n - 1]*/
		dp[0] = nums[0];
		dp[1] = max(dp[0], nums[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}

		return max(dp[n - 2], answer);
	}
};
