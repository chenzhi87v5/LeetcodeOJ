/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

//1-:二分法

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1, mid;
		while (nums[left] > nums[right]) {
			mid = (left + right) / 2;
			//关键点
			if (nums[mid] >= nums[left && nums[mid] > nums[right]])
				left = mid + 1;
			else
				right = mid;
		}

		return nums[left];
	}
};
