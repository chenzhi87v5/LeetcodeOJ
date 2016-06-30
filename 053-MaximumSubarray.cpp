//Maximum Subarray 最大子数组
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

//最大连续子序列和经典问题
//    对于数组中的一个数2个选择 1.加入之前的subArray 2.自己另起一个subArray
/*
这道题让我们求最大子数组之和，并且要我们用两种方法来解，分别是O(n)的解法，还有用分治法Divide and Conquer Approach，这个解法的时间复杂度是O(nlogn)，那我们就先来看O(n)的解法，定义两个变量res和tmp，其中res保存最终要返回的结果，即最大的子数组之和，tmp是个临时变量，初始值为数组的第一个数，每遍历一个数字A[i]，比较tmp + A[i]和A[i]中的较大值存入tmp，然后再把res和tmp中的较大值存入res，以此类推直到遍历完整个数组，可得到最大子数组的值存在res中，代码如下： 
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

/*
题目还要求我们用分治法Divide and Conquer Approach来解，这个分治法的思想就类似于二分搜索法，我们需要把数组一分为二，分别找出左边和右边的最大子数组之和，然后还要从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最大的那一个，代码如下： 
*/
//参考解法  了解 
class Solution {
public:
	int maxSubArray(int A[], int n) {
		return getMaxSubArray(A, 0, n - 1);
	}
	
	int getMaxSubArray(int A[], int left, int right) {
		if (left >= right) return A[left];
		int mid = (left + right) / 2;
		int lmax = getMaxSubArray(A, left, mid - 1);
		int rmax = getMaxSubArray(A, mid + 1, right);
		int mmax = A[mid], tmp = A[mid];
		for (int i = mid - 1; i >= left; --i) {
			tmp += A[i];
			mmax = max(mmax, tmp);
		}
		tmp = mmax;
		for (int i = mid + 1; i <= right; ++i) {								
			tmp += A[i];				
			mmax = max(mmax, tmp);
		}
		return max(mmax, max(lmax, rmax));	
	}
};
