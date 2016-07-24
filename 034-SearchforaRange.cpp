//Search for a Range 搜索一个范围
/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
//真正意义上的O(logn)的算法，使用两次二分查找法，第一次找到左边界，第二次调用找到右边界即可，具体代码如下：
//使用二分查找寻找左右边界，比较巧妙
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2, -1);
		int start = 0, end = nums.size() - 1;
		
		//二分查找法，第一次找到左边界
		while (start < end) {
			int mid = (start + end) / 2;
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (nums[start] != target)
			return res;
		res[0] = start;
		
		//二分查找法，第二次找到右边界
		end = nums.size();
		while (start < end) {
			int mid = (start + end) / 2;
			if (nums[mid] > target)
				end = mid;
			else
				start = mid + 1;
		}
		res[1] = start - 1;
		
		return res;
	}
}
