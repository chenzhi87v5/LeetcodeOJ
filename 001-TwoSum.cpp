//Two Sum 两数之和
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */

/*2-hash 哈希表存储每个数对应的下标，时间复杂度n 空间复杂度n*/
//unordered_map 使用

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mapping;
		vector<int> result;
		
		for (int i = 0; i < nums.size(); i++) {
			mapping[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			const int gap = target - nums[i];
			if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
				result.push_back(i);
				result.push_back(mapping[gap]);
				break;
			}
		}
		return result;
	}
};
//mapping.find(gap) != mapping.end() or mapping.count(gap)
