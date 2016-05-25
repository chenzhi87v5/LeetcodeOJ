/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/

//使用map

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int> buf;
		for (int i = 0; i < nums.size(); i++) {
			if (buf.find(nums[i]) != buf.end() && i - buf[nums[i]] <= k) {
				return true;
			} else {
				buf[nums[i]] = i;
			}
		}

		return false;
	}
};
