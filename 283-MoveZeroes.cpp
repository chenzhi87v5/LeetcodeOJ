//Move Zeroes 移动零
/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
	You must do this in-place without making a copy of the array.
	Minimize the total number of operations.
*/

/*
这道题让我们将一个给定数组中所有的0都移到后面，把非零数前移，要求不能改变非零数的相对应的位置关系，而且不能拷贝额外的数组，那么只能用替换法in-place来做，需要用两个指针，一个不停的向后扫，找到非零位置，然后和前面那个指针交换位置即可 
*/
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; i < nums.size(); i++) {
			if (nums[i]) {
				swap(nums[i], nums[j++]);
			}
		}
	}
};
