//3Sum Closest 最近三数之和
/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*1-mySolution*/
// 排序左右夹逼,时间复杂度n^2 
/*
这道题让我们求最接近给定值的三数之和，是在之前那道 3Sum 三数之和的基础上又增加了些许难度，那么这道题让我们返回这个最接近于给定值的值，即我们要保证当前三数和跟给定值之间的差的绝对值最小，所以我们需要定义一个变量min_gap用来记录差的绝对值，然后我们还是要先将数组排个序，然后开始遍历数组，思路跟那道三数之和很相似，都是先确定一个数，然后用两个指针start和end来滑动寻找另外两个数，每确定两个数，我们求出此三数之和，然后算和给定值的差的绝对值存在gap中，然后和min_gap比较并更新min_gap和结果result即可，代码如下： 
*/
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int min_gap = INT_MAX;
		sort(nums.begin(), nums.end());
		
		for (int i = 0; i < nums.size() - 2; i++) {
			int start = i + 1;
			int end = nums.size() - 1;
			while (start < end) {
				int sum = nums[i] + nums[start] + nums[end];
				int gap = abs(target - sum);
				if (gap < min_gap) {
					min_gap = gap;
					result = sum;
				}
				//关键循环判定条件
				if (sum < target)
					start++;
				else
					end--;
			}
		}
		return result;
	}
};

