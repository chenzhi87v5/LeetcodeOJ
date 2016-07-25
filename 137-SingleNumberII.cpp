//Single Number II 单独的数字之二
/*
Given an array of integers, every element appears three times except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

//创建一个长度为sizeof(int) 的数组count[sizeof(int)]，count[i] 表示在在i位
    //出现的1的次数。如果count[i] 是3的整数倍，则忽略否则就把该位取出来组成答案。
//时间复杂度n 空间复杂度 1
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];

		const int W = sizeof(int) * 8; 	//整数bit位数			            
		int count[W]; 			//count[i] 表示i位出现1的次数
		fill_n(&count[0], W, 0); 	//STL fill_n 函数

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < W; j++) {
				count[j] += (nums[i] >> j) & 1;   //统计每个bit出现的次数
				count[j] %= 3;                    //过滤
			}
		}

		int result = 0;
		for (int i = 0; i < W; i++) {
			result += (count[i] << i);   //结果
		}

		return result;
	}
};
