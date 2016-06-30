//Remove Element 移除元素
/*
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/

/*1-mySolution*/
//这道题让我们移除一个数组中和给定值相同的数字，并返回新的数组的长度。是一道比较容易的题，我们只需要一个变量用来计数，然后遍历原数组，如果当前的值和给定值不同，我们就把当前值覆盖计数变量的位置，并将计数变量加1。代码如下：
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		//解法一 使用STL 
		//return distance(num.begin(), remove(nums.begin(), nums.end(), val));
		
		//解法二 
		int index = 0;
		for (int i = 0; i < nums.size(); i++ )
			if (nums[i] != val) {
				nums[index] = nums[i];
				index++;
			}
		return index;
	}
};
