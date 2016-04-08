/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*1-mySolution*/
// 排序左右夹逼,时间复杂度n^2 
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		int min_gap = INT_MAX;
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
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

