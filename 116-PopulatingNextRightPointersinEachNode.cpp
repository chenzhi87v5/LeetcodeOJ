/*
Given a binary tree

    struct TreeLinkNode {
          TreeLinkNode *left;
	  TreeLinkNode *right;
	  TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

	You may only use constant extra space.
	You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
        / \
      2    3
     / \  / \
    4  5  6  7
    
    After calling your function, the tree should look like:
    		1 -> NULL
       	       / \
	      2 -> 3 -> NULL
	     / \  / \
	    4->5->6->7 -> NULL
*/
/**
  * Definition for binary tree with next pointer.
  * struct TreeLinkNode {
  *  int val;
  *  TreeLinkNode *left, *right, *next;
  *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  * };
  */

//1-: 递归法 与 迭代法
//使用迭代法 使用 双队列 类似二叉树的层次遍历
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		queue<TreeLinkNode*> current, next;    //双队列
		current.push(root);
	
		while (!current.empty()) {
			while(!current.empty()) {
				TreeLinkNode* node = current.front();
				current.pop();
				TreeLinkNode* nnode;
				if (!current.empty()) {
					nnode = current.front();
				} else {
					nnode = NULL;
				}
				node->next = nnode;    //next 连接
				
				if (node->left != NULL)       //node 下一层加入
					next.push(node->left);
				if (node->right != NULL)
					next.push(node->right);
			}
			swap(current, next);
		}

		return;
	}
};

//递归法：时间复杂度n 空间复杂度logn
//思路比较复杂
class Solution {
public:
	void connect(TreeLinkNode *root) {
		connect(root, NULL);
	}

private:
	void connect(TreeLinkNode *root, TreeLinkNode *sibling) { //sibling root平行的下一个分支
		if (root == NULL)   //剪枝，返回
			return;
		else
			root->next = sibling;

		connect(root->left, root->right); //考虑root 下一层

		if (sibling)
			connect(root->right, sibling->left);  
		else
			connect(root->right, NULL); 
	}
};

