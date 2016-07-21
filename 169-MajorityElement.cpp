//Majority Element 求众数
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/
/*
这是到求众数的问题，有很多种解法，可参见网友烟雨林的博客，其中我感觉比较好的有两种，一种是用哈希表，这种方法需要O(n)的时间和空间，另一种是用一种叫摩尔投票法 Moore Voting，需要O(n)的时间和O(1)的空间，比前一种方法更好。这种投票法先将第一个数字假设为众数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将当前值设为候选众数。以此类推直到遍历完整个数组，当前候选众数即为该数组的众数。代码如下： 
*/
//巧妙思想， 精辟 时间复杂度n 空间复杂度1
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int Idx = 0, count = 1;
		for (int i = 1; i < nums.size(); i++) {
			nums[Idx] == nums[i] ? count++ : count--;
			if (count == 0) {
				Idx = i;
				count = 1;
			}
		}
		return nums[Idx];
	}
};
