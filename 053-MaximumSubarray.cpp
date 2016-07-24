//Maximum Subarray 最大子数组
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle.
*/

//最大连续子序列和经典问题
//对于数组中的一个数2个选择 1.加入之前的subArray 2.自己另起一个subArray
/*
这道题让我们求最大子数组之和，O(n)的解法,那我们就先来看O(n)的解法，定义两个变量res和tmp，其中res保存最终要返回的结果，
即最大的子数组之和，tmp是个临时变量，初始值为数组的第一个数，每遍历一个数字A[i]，比较tmp + A[i]和A[i]中的较大值存入tmp，
然后再把res和tmp中的较大值存入res，以此类推直到遍历完整个数组，可得到最大子数组的值存在res中，代码如下： 
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int res = nums[0], tmp = res;
		
		for (int i = 1; i < nums.size(); i++) {
			tmp = max(tmp + nums[i], nums[i]);
			res = max(res, tmp);
		}
		
		return res;
	}
};
