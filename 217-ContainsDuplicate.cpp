//Contains Duplicate 包含重复值
/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value 
appears at least twice in the array, and it should return false if every element is distinct. 
*/

//法一：排序 然后前后对比
//法二：使用hash set: unordered_set

/*
哈希表，遍历整个数组，如果哈希表里存在，返回true，如果不存在，则将其放入哈希表中，代码如下： 
*/
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return false;
		
		unordered_set<int> nums_s;
		for (int i =0; i < nums.size(); i++) {
			if (nums_s.find(nums[i]) != nums_s.end()) {
				return true;
			} else {
				nums_s.insert(nums[i]);
			}
		}

		return false;
	}
};
