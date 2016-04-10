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
