//Two Sum 两数之和
/*
   Given an array of integers, return indices of the two numbers such that they add up to a specific target.

   You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

 */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*1-暴力解法:时间复杂度n^2，超时*/

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

int main()
{
	int nums[4] = {2, 7, 11, 15};
	vector<int> num(nums, nums+4);
	int target = 9;
	
	Solution test;
	
	vector<int> res = test.twoSum(num, target);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++){
		cout<< *it <<endl;
	}

	return 0;
}
