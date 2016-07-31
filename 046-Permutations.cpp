//Permutations 全排列
/*
Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> tmp;
		dfs(nums, tmp, result);
		return result;
	}

	void dfs(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& result) {
		//收敛条件
		if (tmp.size() == nums.size()) {
			result.push_back(tmp);
			return;
		}
		//扩展状态
		for (auto i : nums) {
			//查找i是否在tmp中出现过
			auto pos = find(tmp.begin(), tmp.end(), i);     //STL find 函数
			if (pos == tmp.end()) {
				tmp.push_back(i);
				dfs(nums, tmp, result);
				tmp.pop_back();	
			}
		}
	}
};
