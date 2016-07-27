//House Robber III 打家劫舍之三
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in 
this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into 
on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
	3
       / \
      4   5
     / \   \ 
    1   3   1
    
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
 */

//打家劫舍之三  这道题是之前那两道House Robber II和House Robber的拓展

/*
这种问题是很典型的递归问题，我们可以利用回溯法来做，因为当前的计算需要依赖之前的结果，那么我们对于某一个节点，如果其左子节
点存在，我们通过递归调用函数，算出不包含左子节点返回的值，同理，如果右子节点存在，算出不包含右子节点返回的值，那么此节点的
最大值可能有两种情况，一种是该节点值加上不包含左子节点和右子节点的返回值之和，另一种是左右子节点返回值之和不包含当期节点值
，取两者的较大值返回即可
*/
//我们可以把已经算过的节点用哈希表保存起来，以后递归调用的时候，现在哈希表里找，如果存在直接返回，如果不存在，等计算出来后
//，保存到哈希表中再返回，这样方便以后再调用，参见代码如下：
class Solution {
public:
	int rob(TreeNode* root) {
		unordered_map<TreeNode*, int> m;
		return dfs(root, m);	
	}

	int dfs(TreeNode *root, unordered_map<TreeNode*, int> &m) {
		if (!root)
			return 0;

		if (m.count(root))  	   //hash表中判断是否存在某个值 .count() 函数
			return m[root];
		
		int val = 0;
		if (root->left) {
			val += dfs(root->left->left, m) + dfs(root->left->right, m);
		}
		if (root->right) {
			val += dfs(root->right->left, m) + dfs(root->right->right, m);
		}
		
		val = max(val + root->val, dfs(root->left, m) + dfs(root->right, m));
		
		m[root] = val;
		return val;
	}
};
