//Single Number III 单独的数字之三

/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly 
twice. Find the two elements that appear only once.

For example:  Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
  The order of the result is not important. So in the above example, [5, 3] is also correct.
  Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?*/

//如何将二者分开 网友的介绍是利用两个元素的异或值（说明，要找的元素的对应位不同），利用这个特点将原有的序列分为两部分
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;       
		if (nums.size() == 0)            	 //参数检测
			return res;
		
		int x = 0, len = nums.size(), pos;
		for (int i = 0; i < len; i++) {
			x ^= nums[i];
		}
		
		//将两个两个元素不同的位取出来pos
		for (int i = 0; i < 32; i++)
			if (x & (1 << i)) {
				pos = i;
				break;
			}
		
		vector<int> results(2);   		 //结果集
		for (int i = 0; i < len ; i++) {         //利用pos位 将两个元素提取出来
			if (nums[i] & (1 << pos))
				results[0] ^= nums[i];
			else
				results[1] ^= nums[i];
		}
		return results;
	}	
};
