/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

//巧妙思想， 精辟 时间复杂度n 空间复杂度1
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int candidate, count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (count == 0) {
				candidate = nums[i];
				count++;
			} else {
				if (candidate == nums[i]) {
					count++;	
				} else {
					count--;
				}
			}
		}

		return candidate;
	}
};