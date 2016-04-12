/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

// 1-暴力解法 超时
// 2-最大连续子序列和经典问题
//    对于数组中的一个数2个选择 1.加入之前的subArray 2.自己另起一个subArray
//    选一个数来界定 0

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN, f = 0;
		
		for (int i = 0; i < nums.size(); i++) {
			f = max(f + nums[i], nums[i]);
			result = max(result, f);
		}
		
		return result;
	}
};

