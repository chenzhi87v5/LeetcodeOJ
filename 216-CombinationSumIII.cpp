//Combination Sum III 组合之和之三
/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used 
and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:
	Input: k = 3, n = 7
Output:
	[[1,2,4]]

Example 2:
	Input: k = 3, n = 9
Output:
	[[1,2,6], [1,3,5], [2,3,4]]
*/

//深度优先搜索法DFS

/*这道题题是组合之和系列的第三道题，跟之前两道Combination Sum 组合之和，Combination Sum II 组合之和之二都不太一样，那两道的
联系比较紧密，变化不大，而这道跟它们最显著的不同就是这道题的个数是固定的，为k。个人认为这道题跟那道Combinations 组合项更相
似一些，但是那道题只是排序，对k个数字之和又没有要求。所以实际上这道题是它们的综合体，两者杂糅到一起就是这道题的解法了，n是
k个数字之和，如果n小于0，则直接返回，如果n正好等于0，而且此时out中数字的个数正好为k，说明此时是一个正确解，将其存入结果
res中，具体实现参见代码入下：*/
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> out;
		dfs(k, n, 1, out, res);
		return res;
	}

	//DFS 深度递归
	void dfs(int k, int n, int level, vector<int> &out, vector<vector<int>> &res) {
		if (n < 0)  //剪枝
			return;
		if (n == 0 && out.size() == k) //结果
			res.push_back(out);
		for (int i = level; i <= 9; i++) { 
			//扩展
			out.push_back(i);
			dfs(k, n - i, i + 1, out, res);
			out.pop_back();
		}
	}
};
