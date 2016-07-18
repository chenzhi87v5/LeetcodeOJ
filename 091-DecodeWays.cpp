//Decode Ways 解码方法
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
*/

//动态规划 类似Climbing Stairs   dp
//f(n) = f(n - 1) + f(n - 2)
//nums[i] 表示字符串s[0]到s[i - 1]解码方法
class Solution {
public:
	int numDecodings(string s) {
		if(s.empty())
			return 0;
		int *nums = new int[s.size() + 1];
		int res;
		
		fill(nums, nums + s.size() + 1, 0)    //STL fill函数
		nums[0] = 1;
		nums[1] = s[0] != '0' ? 1 : 0;	      //只有一个数字并且不为0时有1个解法

		for (int i = 2; i <= s.size(); i++) {
			if (s[i - 1] != '0') {
				nums[i] = nums[i - 1];
			}

			int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
			if (twoDigits >= 10 && twoDigits <= 26) {
				nums[i] += nums[i - 2];
			}
		}

		res = nums[s.size()];
		delete nums;

		return res;
	}
};
