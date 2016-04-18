/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

//1-:
//二分查找，难度在于左右边界的确定

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int first = 0, last = nums.size();

		while (first != last) {
			const int mid = (first + last) / 2;
			if (nums[mid] == target)       //找到目标值
				return mid;
			if (nums[first] <= nums[mid]) {        //左值小于等于中值
				if (nums[first] <= target && target < nums[mid])    
					last = mid;
				else
					first = mid + 1;
			} else {                                //左值大于中值
				if (nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}

		return -1;
	}
};
