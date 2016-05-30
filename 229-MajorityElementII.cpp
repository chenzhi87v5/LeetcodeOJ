/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

//找出出现次数超过n/3的元素 ：最多就有两个元素 最少一个都没有
//类似Majority Number I 算法 巧妙

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
		if (nums.size() == 0)   //参数检查
			return res;

		int candidate1, candidate2;
		int count1, count2;

		count1 = count2 = 0;
		for (int i = 0; i < nums.size(); i++) {    //统计出现次数最大的两个元素
			if (candidate1 == nums[i]) {
				count1++;
			} else if (candidate2 == nums[i]) {
				count2++;
			} else if (count1 == 0) {
				candidate1 = nums[i];
				count1 = 1;
			} else if (count2 == 0) {
				candidate2 = nums[i];
				count2 = 1;
			} else {
				count1--;
				count2--;
			}
		}

		count1 = count2 =0;                     //计算最大两个元素出现次数
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == candidate1) {
				count1++;
			} else if (nums[i] == candidate2) {
				count2++;
			}
		}
		//判断是否加入结果集
		if (count1 > nums.size() / 3) {
			res.push_back(candidate1);
		}
		if (count2 > nums.size() / 3) {
			res.push_back(candidate2);
		}

		return res;
	}
};
