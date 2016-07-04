//Maximum Product Subarray 求最大子数组乘积
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

/*
动态规划 一个记录max  一个记录min
以下摘自OJ官方解答，大体思路相同，写法更加简洁：

Besides keeping track of the largest product, we also need to keep track of the smallest product. Why? The smallest product, which is the largest in the negative sense could become the maximum when being multiplied by a negative number.

Let us denote that:
f(k) = Largest product subarray, from index 0 up to k.
 
Similarly,
g(k) = Smallest product subarray, from index 0 up to k.
 
Then,
f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )
 
There we have a dynamic programming formula. Using two arrays of size n, we could deduce the final answer as f(n-1). Since we only need to access its previous elements at each step, two variables are sufficient.
*/
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int res = nums[0], mn = nums[0], mx = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int tmax = mx, tmin = mn;
			mx = max(max(nums[i], tmax * nums[i]), tmin * nums[i]);
			mn = min(min(nums[i], tmax * nums[i]), tmin * nums[i]);
			res = max (res, mx);
		}

		return res;
	}
}
