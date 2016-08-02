//Majority Element II 求众数之二
/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in 
linear time and in O(1) space.

Hint:
How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

//找出出现次数超过n/3的元素 ：最多就有两个元素 最少一个都没有     类似Majority Number I 算法 巧妙

/*题目中给了一条很重要的提示，让我们先考虑可能会有多少个众数，经过举了很多例子分析得出，任意一个数组出现次数大于n/3的众数最
多有两个，具体的证明我就不会了，我也不是数学专业的。那么有了这个信息，我们使用投票法的核心是找出两个候选众数进行投票，需要
两遍遍历，第一遍历找出两个候选众数，第二遍遍历重新投票验证这两个候选众数是否为众数即可，选候选众数方法和前面那篇
Majority Element 求众数一样，由于之前那题题目中限定了一定会有众数存在，故而省略了验证候选众数的步骤，这道题却没有这种限定
，即满足要求的众数可能不存在，所以要有验证。 */

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> res;
		if (nums.size() == 0)   //参数检查
			return res;

		int candidate1, candidate2;
		int count1, count2;

		//统计出现次数最大的两个元素
		candidate1 = candidate2 = 0;
		count1 = count2 = 0;
		for (int i = 0; i < nums.size(); i++) { 
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
		//计算最大两个元素出现次数
		count1 = count2 =0;               
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
