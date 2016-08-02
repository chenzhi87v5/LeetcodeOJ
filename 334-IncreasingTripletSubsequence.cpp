//Increasing Triplet Subsequence 递增的三元子序列

/*Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

/*我们下面来看满足题意的方法，这个思路是，我们遍历数组，维护一个最小值，和倒数第二小值，遍历原数组的时候，如果当前数字小于等
于最小值，更新最小值，如果小于等于倒数第二小值，更新倒数第二小值，如果当前数字比最小值和倒数第二小值都大，说明此时有三个递
增的子序列了，直接返回ture，否则遍历结束返回false，参见代码如下： */

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		
		int m1 = INT_MAX, m2 = INT_MAX;

		for (auto a : nums) {
			if (m1 >= a)
				m1 = a;
			else if (m2 >= a)
				m2 = a;
			else
				return true;
		}

		return false;
	}
};
