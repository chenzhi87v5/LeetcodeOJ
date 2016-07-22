//Flatten Binary Tree to Linked List 将二叉树展开成链表
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
/*
这道题要求把二叉树展开成链表，根据展开后形成的链表的顺序分析出是使用先序遍历，首先来看递归版本的，思路是先利用DFS的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。代码如下： 
*/
class Solution {
public:
	void flatten(TreeNode* root) {
		 if (!root) return;
		 if (root->left) flatten(root->left);
		 if (root->right) flatten(root->right);
		 TreeNode *tmp = root->right;
		 root->right = root->left;
		 root->left = NULL;
		 while (root->right) root = root->right;
		 root->right = tmp;
	}
};
/*
例如，对于下面的二叉树，上述算法的变换的过程如下：
	1
       / \
      2   5
     / \   \
    3   4   6
     	
    	1
       / \
      2   5
       \   \
        3   6
	 \    
	  4

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
*/
