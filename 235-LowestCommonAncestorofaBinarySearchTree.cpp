//Lowest Common Ancestor of a Binary Search Tree 二叉搜索树的最小共同父节点
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
  0      _4       7       9
        /  \
        3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
//如果如果p,q 比root小, 则LCA必定在左子树, 如果p,q比root大, 则LCA必定在右子树. 如果一大一小, 则root即为LCA.
//法一：递归法
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == NULL || q == NULL)
			return NULL;

		if (p->val < root->val && q->val < root->val) {
			return lowestCommonAncestor(root->left, p, q);
		} else if (p->val > root->val && q->val > root->val) {
			return lowestCommonAncestor(root->right, p, q);
		} else {
			return root;
		}
	}
};

//法二:非递归 迭代法
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *cur = root;
		while (cur != NULL) {
			if (cur->val > p->val && cur->val > q->val)
				cur = cur->left;
			else if (cur->val < p->val && cur->val < q->val)
				cur = cur->right;
			else
				return cur;
		}
		return cur;
	}
};
