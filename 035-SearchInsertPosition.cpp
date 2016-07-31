//Search Insert Position 搜索插入位置
/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where 
it would be if it were inserted in order.
You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

/*
用二分搜索法来优化我们的时间复杂度，而且个人认为这种方法应该是面试官们想要考察的算法吧，参见代码如下： 
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//为空 第一个 最后一个判断
		if (nums.empty())
			return 0;
		if (nums[0] > target)
			return 0;
		if (nums.back() < target) 
			return nums.size();
		
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return right;
	}
}
