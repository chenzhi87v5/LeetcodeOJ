//Single Number 单独的数字
/*
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

//异或，不仅能处理两次的情况，只要出现偶数次，都可以清零
// ^ 异或 每一位相同取0 不同取1

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int x = 0;		
		for (size_t i = 0; i < nums.size(); i++) {
			x ^= nums[i];
		}
		return x;
	}
};
