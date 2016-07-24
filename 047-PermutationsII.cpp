//Permutations II 全排列之二
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
/*
这道题是之前那道 Permutations 全排列的延伸，由于输入数组有可能出现重复数字，如果按照之前的算法运算，会有重复排列产生，
我们要避免重复的产生，在递归函数中要判断前面一个数和当前的数是否相等，如果相等，前面的数必须已经使用了，
即对应的visited中的值为1，当前的数字才能使用，否则需要跳过，这样就不会产生重复排列了，代码如下：
*/
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

			//与前面一个数相等 且前面一个数已经使用才能继续，否是跳过1
			if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1]) {
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
