//Search in Rotated Sorted Array II 在旋转有序数组中搜索之二
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/

//允许重复元素,如果nums[j]<=nums[i],那么[j,i]为递增序列的假设就不能成立了，比如1,3,1,1,1
/*
如果nums[i]>=nums[j] 不能确定递增，那就把它拆分成两个条件：
	若nums[i]>nums[j]，则区间[j,i] 一定递增
	若nums[i]==nums[j] 确定不了，那就j++，往下看一步即可。
*/
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int first = 0, last = nums.size();

		while (first != last) {
			const int mid = (first + last) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[first] < nums[mid]) {
				if (nums[first] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			} else if (nums[first] > nums[mid]) {
				if (nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			} else
				first++;	//skip duplicate one 与在旋转有序数组中搜索之一	区别			
		}

		return false;
	}
};
