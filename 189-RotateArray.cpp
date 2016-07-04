//Rotate Array 旋转数组
/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II
*/

//三次翻转数组  自己实现的reverse 与标准STL reverse区别 reverse(beg, end) beg end均是迭代器
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) {
			return;
		}
		k = k % nums.size();   
		reverse(nums, 0, nums.size() - k - 1);
		reverse(nums, nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);
		return;
	}
private:
	void reverse(vector<int>& nums, int start, int end) {
		while (start < end) {
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start++;
			end--;
		}
	}
};

