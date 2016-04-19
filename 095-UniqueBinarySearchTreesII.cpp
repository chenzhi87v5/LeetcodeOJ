/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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

//1-:二叉查找树 递归
//生成所有的二叉查找树 有点难度 *****
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode *> subTree;
		if (n == 0)                   //返回空树
			return subTree;
		
		return generate(1, n);
	}
private:
	vector<TreeNode *> generate(int start, int end) {
		vector<TreeNode *> subTree;
		if (start > end) {                    //start 大于 end 时子返回空子树
			subTree.push_back(NULL);
			return subTree;
		}
		for (int k = start; k <=end; k++) {           
			vector<TreeNode *> leftSubs = generate(start, k - 1);   //左子树 [start, k - 1]
			vector<TreeNode *> rightSubs = generate(k + 1, end);     //右子树[k + 1, end]
			
			for (auto i : leftSubs) {                                //左右子树互相组合
				for (auto j : rightSubs) {
					TreeNode *node = new TreeNode(k);
					node->left = i;
					node->right = j;
					subTree.push_back(node);                          //加入subTree
				}
			}
		}

		return subTree;
	}
};
