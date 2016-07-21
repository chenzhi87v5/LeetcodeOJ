//Sort Colors 颜色排序
/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
/*
这道题的本质还是一道排序的题，题目中给出提示说可以用计数排序，需要遍历数组两遍，那么先来看这种方法，因为数组中只有三个不同的元素，所以实现起来很容易。
- 首先遍历一遍原数组，分别记录0,1,2的个数
- 然后更新原数组，按个数分别赋上0，1，2

题目中还要让只遍历一次数组来求解，那么我需要用双指针来做，分别从原数组的首尾往中心移动。
- 定义red指针指向开头位置，blue指针指向末尾位置
- 从头开始遍历原数组，如果遇到0，则交换该值和red指针指向的值，并将red指针后移一位。若遇到2，则交换该值和blue指针指向的值，并将blue指针前移一位。若遇到1，则继续遍历。
*/
//swap 常用STL函数
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0;
		int blue = nums.size() - 1;

		for (int i = 0; i < blue + 1;) {    //注意for第三个参数没有
			if (nums[i] == 0)
				swap(nums[i++], nums[red++]);
			else if (nums[i] == 2)
				swap(nums[i], nums[blue--]);
			else
				i++;
		}
	}
};
