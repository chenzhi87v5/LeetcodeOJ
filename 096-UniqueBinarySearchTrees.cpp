/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//1-:二叉查找树
//解法: 数学规律，递推公式
//以i为根的树的个数，等于左子树的个数乘以右子树的个数
//基于以下原则构建的BST树具有唯一性，以i为根节点的树,左子树由[1, i-1]构成
//				     右子树由[i+1, n]构成
//时间复杂度n^2 空间复杂度n
class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n + 1, 0);

		f[0] = 1; //无节点 空树，只有一种BST
		f[1] = 1; //一个节点，只有一种BST

		for (int i = 2; i <= n ; i++) {
			for (int k = 1; k <= i; k++) {
				f[i] += f[k - 1] * f[i - k];
			}
		}
		
		return f[n];
	}
};
