//Subsets II 子集合之二
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
]
*/

//对比Subsets 题无重复元素相当于每个元素只能选0或者1次，这里扩充到每个元素可以选0到若干次
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		vector<int> path;

		dfs(nums, nums.begin(), path, result);

		return result;
	}
private:
	static void dfs(const vector<int> &nums, vector<int>::iterator start, vector<int> &path, vector<vector<int>>&result) {
		result.push_back(path); //加入path

		for(auto i = start; i < nums.end(); i++) {
			if (i != start && *i == *(i - 1))  //重复元素滤过
				continue;
			path.push_back(*i);
			dfs(nums, i + 1, path,result);
			path.pop_back();
		}
	}
};
