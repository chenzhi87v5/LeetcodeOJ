/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

        A solution set is:
	(-1,  0, 0, 1)
        (-2, -1, 1, 2)
	(-2,  0, 0, 2)
*/

/*1-mySolution*/
//根据3SUM 解决问题 
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		
		if (nums.size() < 4)
			return result;
		
		sort(nums.begin(), nums.end());
		
		for (int a = 0; a < nums.size() - 3; a++) {   // 注意 -3
			if (a > 0 && nums[a] == nums[a - 1])    //去重
				continue;
			for (int b = a + 1; b < nums.size() - 2; b++) { //注意 - 2
				if (b > a + 1 && nums[b] == nums[b - 1])   //去重
					continue;
				int c = b + 1;
				int d = nums.size() - 1;
				while (c < d) {
					int sum = nums[a] + nums[b] + nums[c] + nums[d];
					if (sum < target) {
						c++;
					} else if (sum > target) {
						d--;
					} else {
						result.push_back({nums[a], nums[b], nums[c], nums[d]});
						c++;
						d--;
						while (c < d && nums[c] == nums[c - 1])   //关键1 去重
							c++;
						while (c < d && nums[d] == nums[d + 1])   //关键2 去重
							d--;
					}
				}
			}
		}
		
		return result;
	}
};
