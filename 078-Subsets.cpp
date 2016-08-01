//Subsets 子集合
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
/*
递归的解法，相当于一种深度优先搜索，参见网友JustDoIt的博客，由于原集合每一个数字只有两种状态，要么存在，要么不存在，
那么在构造子集时就有选择和不选择两种情况 
*/
//每个元素，都有两种选择，选或者不选 
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

		//不选nums[step]
		subsets(nums, path, step + 1, result);

		//选nums[step]
		path.push_back(nums[step]);
		subsets(nums, path, step + 1, result);
		path.pop_back();
	}
};
