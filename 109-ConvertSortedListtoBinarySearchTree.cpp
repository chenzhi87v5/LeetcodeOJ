/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST. 
*/

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
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

//1-:构建BST 高度平衡二叉树
//法一参考 array 把链表数据存储在array中
//法二 分治法，自顶向下 类似Convert Sorted Array to Binary Search Tree
//时间复杂度n^2
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return sortedListToBST(head, ListLength(head));
	}

	//递归函数
	TreeNode* sortedListToBST(ListNode* head, int len) {
		if (len == 0)
			return NULL;
		if (len == 1)
			return new TreeNode(head->val);

		TreeNode* root = new TreeNode(nth_node(head, len / 2 + 1)->val); //中间节点
		root->left = sortedListToBST(head, len / 2);
		root->right = sortedListToBST(nth_node(head, len / 2 + 2), (len - 1) / 2);
	
		return root;
	}

	//求出node链表长度
	int ListLength(ListNode *node) {
		int n = 0;
		while(node) {
			++n;
			node = node->next;
		}

		return n;
	}
	
	//node指向node后第 n - 1个节点
	ListNode* nth_node(ListNode* node, int n) {
		while(--n) {
			node = node->next;
		}

		return node;
	}
};
