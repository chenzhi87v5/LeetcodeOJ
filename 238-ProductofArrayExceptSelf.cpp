/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

//题意结题，注意边界条件,不能用除法

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<long long> B;
		vector<int> res;
		if (nums.size() == 0 || nums.size() == 1)  //边界检测
			return res;

		int len = nums.size();
		long long f[len + 1];

		f[len] = 1;
		for (int i = len - 1; i >= 0; --i)
			f[i] = f[i + 1] * nums[i];
		long long tmp = 1;
		for (int i = 0; i < len; i++) {
			B.push_back(tmp * f[i + 1]);
			tmp *= nums[i];
		}
		
		//转换为vector<int>
		for (int i = 0; i < B.size(); i++) {
			if (B[i] > INT_MAX) {
				res.push_back(INT_MAX);
			} else if (B[i] < INT_MIN) {
				res.push_back(INT_MIN);
			} else {
				res.push_back(B[i]);
			}
		}
		
		return res;
	}
};
