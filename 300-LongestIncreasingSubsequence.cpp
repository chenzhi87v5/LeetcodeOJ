/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

//最长的递增子序列
/*
动态规划 DP问题:
解题的一般方法就是自下而上，即先求解小的问题，然后再根据小的问题来解决大的问题，最后得到解。
*/

// 时间 O(N^2) 空间 O(N)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		//边界检测	
		if (nums.size() == 0) {
			return 0;
		}
		if (nums.size() == 1) {
			return 1;
		}
		
		//构建最长升序序列长度的数组
		int lis[nums.size()];
		for (int i = 0; i < nums.size(); i++) {
			lis[i] = 0;
		}
		
		lis[0] = 1;
		int max = 0;
		for (int i = 1; i < nums.size(); i++) {
			//找到dp[0]到dp[i-1]中最大的升序序列长度且nums[j]<nums[i]
			for (int j = 0; j < i; j ++) {
				if (nums[j] < nums[i]) {
					lis[i] = lis[i] > lis[j] ? lis[i] : lis[j];
				}
			}
			//加1就是该位置能构成的最长升序序列长度
			lis[i] += 1;
			//更新全局长度
			max = max > lis[i] ? max : lis[i];
		}

		return max;
	}
};
