//4Sum 四数之和 
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
/*时间复杂度n^3*/
//按照 3SUM 解， 套路一个样
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;	
		if (nums.size() < 4)
			return result;
		
		sort(nums.begin(), nums.end());	
		for (int a = 0; a < nums.size() - 3; a++) {   			// 注意 -3
			if (a > 0 && nums[a] == nums[a - 1])    		//去重
				continue;
			for (int b = a + 1; b < nums.size() - 2; b++) { 	//注意 - 2
				if (b > a + 1 && nums[b] == nums[b - 1])   	//去重
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
						while (c < d && nums[c] == nums[c - 1]) c++;   //去重
						while (c < d && nums[d] == nums[d + 1]) d--;   //去重
					}
				}
			}
		}
		
		return result;
	}
};

/*
LeetCode中关于数字之和还有其他几道，分别是Two Sum 两数之和，3Sum 三数之和，3Sum Closest 最近三数之和，虽然难度在递增，但是整体的套路都是一样的，在这里为了避免重复项，我们使用了STL中的set，其特点是不能有重复，如果新加入的数在set中原本就存在的话，插入操作就会失败，这样能很好的避免的重复项的存在。此题的O(n^3)解法的思路跟3Sum 三数之和基本没啥区别，就是多加了一层for循环，其他的都一样，代码如下： 
*/
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &nums, int target) {
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < int(nums.size() - 3); ++i) {
			 for (int j = i + 1; j < int(nums.size() - 2); ++j) {
			 	int left = j + 1, right = nums.size() - 1;
				while (left < right) {
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target) {
						res.insert({nums[i], nums[j], nums[left], nums[right]});
						left++;
						right--;
					} else if (sum < target) ++left;
					else --right;
				}
			 }
		}

		return vector<vector<int>> (res.begin(), res.end());
	}
}
