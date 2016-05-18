/*  
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

//O(n)解法：滑动窗口法，使用两个下标left和right标识窗口（子数组）的左右边界

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int left = 0, right = 0, total = 0, ans = n + 1;
		while (right < n) {
			while (right < n && total < s)
				total += nums[right++];
			if (total < s)
				break;
			while (left < right && total >= s)
				total -= nums[left++];
			ans = min(ans, right - left + 1);
		}

		if (ans == n + 1)
			return 0;
		else
			return ans;
	}
};
