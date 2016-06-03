/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

//寻找丢失的数字
//先排序 再查找
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		
		int n = nums.size();
		for (int i=0; i<n; ++i)
			if (nums[i]!=i) return i;
			        
		return n;
	}
};
