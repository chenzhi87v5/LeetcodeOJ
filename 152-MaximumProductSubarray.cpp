//Maximum Product Subarray 求最大子数组乘积
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

//1-: 考虑特殊情况有多个负值时候
//双vector 解决时间复杂度 n 空间复杂度 n  (精辟)
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		//两个vector 记录当前最大 与 最小
		vector<int> f, g;
		f.push_back(nums[0]);
		g.push_back(nums[0]);

		for (int i = 1; i < nums.size(); i++) {
			f.push_back(max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]));
			g.push_back(min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]));
		}

		int m = f[0];
		for (int i = 1; i < f.size(); i++)
			m = max(m, f[i]);
	
		return m;
	}
};
