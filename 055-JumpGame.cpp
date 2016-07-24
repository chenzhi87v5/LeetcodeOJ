//Jump Game 跳跃游戏
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/

/*
一种省空间的DP方法，维护一个常量maxIdx，表示最远能到达的位置，遍历数组中每一个数字，如果当前坐标大于maxIdx或者maxIdx已经抵达
最后一个位置则跳出循环，否则就更新maxIdx的值为其和i + A[i]中的较大值，其中i + A[i]表示当前位置能到达的最大位置，代码如下：
*/
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxIdx = 0;
		 
		for (int i = 0; i < nums.size();i++) {
			if (i > maxIdx || maxIdx > nums.size() - 1)
				break;
			maxIdx = max(maxIdx, i + nums[i]);
		}
		
		return maxIdx >= nums.size() - 1;
	}
};
