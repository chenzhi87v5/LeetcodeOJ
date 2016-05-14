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

//两种方法：
//一种易读(运行效率低,依次旋转)
//一种高效(运行效率高三次reverse数组旋转)
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0) {
			return;
		}

		k = k % nums.size();   
		reverse(nums, 0, nums.size() - k - 1);           //三次reverse
		reverse(nums, nums.size() - k, nums.size() - 1);
		reverse(nums, 0, nums.size() - 1);

		return;
	}
private:
	//自己实现reverse函数 也可直接使用STL算法reverse函数
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
