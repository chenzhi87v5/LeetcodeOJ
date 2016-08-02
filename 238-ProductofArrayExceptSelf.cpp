//Product of Array Except Self 除本身之外的数组之积

/*Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all 
the elements of nums except nums[i].
Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose 
of space complexity analysis.)*/

//题意结题，注意边界条件,不能用除法
/*
这道题给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，并且限定了时间复杂度O(n)，并且不让
我们用除法。如果让用除法的话，那这道题就应该属于Easy，因为可以先遍历一遍数组求出所有数字之积，然后除以对应位置的上的数字。
但是这道题禁止我们使用除法，那么我们只能另辟蹊径。我们可以先遍历一遍数组，每一个位置上存之前所有数字的乘积。那么一遍下来，
最后一个位置上的数字是之前所有数字之积，是符合题目要求的，只是前面所有的数还需要在继续乘。我们这时候再从后往前扫描，每个
位置上的数在乘以后面所有数字之积，对于最后一个位置来说，由于后面没有数字了，所以乘以1就行。参见代码如下： 
*/
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 1);
		
		for (int i = 1; i < nums.size(); i++) {
			res[i] = res[i - 1] * nums[i - 1];
		}
		
		int right = 1;
		for (int i = nums.size() - 1; i >= 0; --i) {
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
};
