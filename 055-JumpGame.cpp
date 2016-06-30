//Jump Game 跳跃游戏
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.
*/

//1-贪心法
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int reach = 1;
		
		//关键点：循环判断点 reach 
		for (int i = 0; i < reach && reach < nums.size();i++) {
			reach = max(reach, i + 1 + nums[i]);
		}
		
		return reach >= nums.size();
	}
};
