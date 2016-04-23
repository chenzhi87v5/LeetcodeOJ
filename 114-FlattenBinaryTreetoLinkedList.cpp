/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
	/ \
       2   5
      / \   \
     3   4   6
     
    
The flattened tree should look like:
   
    1
     \
      2
       \
        3
	 \
	  4
	   \
	    5
	     \
	      6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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

//1-:递归法 与 迭代法
//递归 时间复杂度n 空间复杂度logn
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)  //终止条件
			return;

		flatten(root->left);   //左
		flatten(root->right);   //右

		if (root->left == NULL)
			return;

		//三方合并，将左子树所形成的链表插入到root 和 root->right 之间
		//问题缩小，考虑最简单情况
		TreeNode *p = root->left;
		while (p->right)
			p = p->right;       //寻找左链表最后一个节点
		p->right = root->right;
		root->right = root->left;
		root->left = NULL;
	}
};
