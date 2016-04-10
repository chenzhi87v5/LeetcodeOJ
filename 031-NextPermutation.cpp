/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/*1-mySolution:*/

/*2-Answers:理解题意，理解"下一个排序算法"算法过程与思想:寻找比当前排列顺序大的下一个相邻排列*/
//学习标准库STL 必须重要
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, j, len = nums.size();
		for (i = len - 2; i >= 0; i--) {
			if (nums[i + 1] > nums[i]) {
				for (j = len - 1; j > i - 1; j--)
					if (nums[j] > nums[i])
						break;
				swap(nums[i], nums[j]);            //STL swap
				reverse(nums.begin() + i + 1, nums.end()); //STL reverse
				return;
			}
		}
		reverse(nums.begin(), nums.end());
		return;
	}
};
