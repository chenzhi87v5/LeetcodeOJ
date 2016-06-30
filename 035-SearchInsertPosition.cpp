//Search Insert Position 搜索插入位置
/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

/*1-mySolution:*/
//二分查找法, 标准库STL算法 next, distance
//重新实现lower_bound
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		return lower_bound_me(nums.begin(), nums.end(), target) - nums.begin();	
	}

	//重新实现的lower_bound
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound_me(ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance(first, last)/2);
			if (value > *mid)
				first = ++mid;
			else
				last = mid;
		}
	
		return first;
	}
};

/*
这道题基本没有什么难度，实在不理解为啥还是Medium难度的，完完全全的应该是Easy啊，三行代码搞定的题，只需要遍历一遍原数组，若当前数字大于或等于目标值，则返回当前坐标，如果遍历结束了，说明目标值比数组中任何一个数都要大，则返回数组长度n即可，代码如下： 
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] >= target) return i;
		}
		
		return nums.size();
	}
}

/*
当然，我们还可以用二分搜索法来优化我们的时间复杂度，而且个人认为这种方法应该是面试官们想要考察的算法吧，参见代码如下： 
*/
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
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
