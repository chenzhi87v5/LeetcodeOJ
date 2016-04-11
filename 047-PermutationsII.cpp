/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

/*1-mySoltion:*/
//递归法，深度优先
//有点难理解
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> results;
		vector<int> permutation;
		bool used[nums.size()];

		fill(used, used + nums.size(), false);
		sort(nums.begin(), nums.end());
		dfs(results, permutation, nums, used);

		return results;
	}

private:
	//总结递归四步走：！！！！
	void dfs(vector<vector<int>>& results, vector<int>& permutation, vector<int>& nums, bool used[]) {
		//1.收敛条件
		if (nums.size() == permutation.size()) {
			results.push_back(permutation);
			return;
		}
		//2.扩展状态
		for(int i = 0; i < nums.size(); i++) {
			//3.排除过滤条件
			if (used[i]) {
				continue;
			}
			if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1]) { //不是很明白?
				continue;
			}
			
			//4.正式处理
			used[i] = true;
			permutation.push_back(nums[i]);
			dfs(results, permutation, nums, used);
			permutation.pop_back();
			used[i] = false;
		}
	}
};
