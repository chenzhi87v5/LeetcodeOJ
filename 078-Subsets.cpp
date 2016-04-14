/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
]
*/

//1-:循环 + 深搜 + 递归 超时！

//2-:每个元素，都有两种选择，选或者不选 
//增量构造法,深搜,时间复杂度2^n 空间复杂度n
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> path;
		subsets(nums, path, 0, result);

		return result;
	}

private:
	static void subsets(const vector<int>& nums, vector<int>& path, int step, vector<vector<int>>& result) {
		if (step == nums.size()) {
			result.push_back(path);
			return;
		}
		//实际处理~~~~
		//不选nums[step]
		subsets(nums, path, step + 1, result);

		//选nums[step]
		path.push_back(nums[step]);
		subsets(nums, path, step + 1, result);
		path.pop_back();
	}
};
