/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

/*1-mySoltion:*/
//深度优先法 递归
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;  
		vector<int> intermediate;     
		sort(candidates.begin(), candidates.end());  //与039题不同，这里每个元素只能用一次

		dfs(candidates, target, 0, intermediate, result);
		return result;
	}

private:
	//使用nums[start, nums.size()] 之间的元素， 能找到的所有可能解
	void dfs(vector<int>& nums, int gap, int start, vector<int>& intermediate, vector<vector<int>>& result) {
		if(gap == 0) {  //找到一个合法解
			result.push_back(intermediate);
			return;
		}
		
		int previous = -1;
		for (size_t i = start; i < nums.size(); i++) {
			//关键点！！！
			//~~~~~~~~~~~
			//如果上一轮循环没有选nums[i],则本次循环就不能再选nums[i]
			//确保nums[i] 最多只用一次
			if (previous == nums[i])
				continue;
			if (gap < nums[i]) //剪枝
				return;
			previous = nums[i];

			intermediate.push_back(nums[i]); //执行扩展动作
			dfs(nums, gap - nums[i], i + 1, intermediate, result);  //变成 i + 1 保障不重复使用
			intermediate.pop_back(); //撤销动作
		}
	}
};
