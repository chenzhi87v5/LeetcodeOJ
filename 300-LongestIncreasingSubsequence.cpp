//Longest Increasing Subsequence 最长递增子序列
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
  The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one 
LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

/*
动态规划 DP问题:  解题的一般方法就是自下而上，即先求解小的问题，然后再根据小的问题来解决大的问题，最后得到解。
首先来看一种动态规划Dynamic Programming的解法，这种解法的时间复杂度为O(n2)，类似brute force的解法，我们维护一个一维dp数组，
其中dp[i]表示以nums[i]为结尾的最长递增子串的长度，对于每一个nums[i]，我们从第一个数再搜索到i，如果发现某个数小于nums[i]，
我们更新dp[i]，更新方法为dp[i] = max(dp[i], dp[j] + 1)，即比较当前dp[i]的值和那个小于num[i]的数的dp值加1的大小，我们就这样
不断的更新dp数组，到最后dp数组中最大的值就是我们要返回的LIS的长度，参见代码如下：  时间 O(N^2) 空间 O(N)
*/
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
		
		vector<int> dp(nums.size(), 1);
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] >= nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}

		return res;
	}
};

/*
 一种优化时间复杂度到O(nlgn)的解法，这里用到了二分查找法，所以才能加快运行时间哇，思路是先建立一个空的dp数组，然后开始遍历
 原数组，对于每一个遍历到的数字，我们用二分查找法在dp数组找第一个不小于它的数字，如果这个数字不存在，那么直接在dp数组后面加
 上遍历到的数字，如果存在，则将这个数字更新为当前遍历到的数字，最后返回dp数字的长度即可，注意的是，跟上面的方法一样，特别注
 意的是dp数组的值可能不是一个真实的LIS。参见代码如下： 
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		for (int i = 0; i < nums.size(); ++i) {
			int left = 0, right = dp.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (dp[mid] < nums[i]) left = mid + 1;
				else right = mid;
			}
			if (right >= dp.size()) dp.push_back(nums[i]);
			else dp[right] = nums[i];
		}

		return dp.size();
	}
}
