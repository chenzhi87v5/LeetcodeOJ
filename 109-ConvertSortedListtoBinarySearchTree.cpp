//Convert Sorted List to Binary Search Tree 将有序链表转为二叉搜索树
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

/*
构建BST 高度平衡二叉树
法一参考 array 把链表数据存储在array中
法二 分治法，自顶向下 类似Convert Sorted Array to Binary Search Tree  时间复杂度n^2
*/
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
/*
这道题是要求把有序链表转为二叉搜索树，和之前那道Convert Sorted Array to Binary Search Tree 将有序数组转为二叉搜索树思路完全一样，只不过是操作的数据类型有所差别，一个是数组，一个是链表。数组方便就方便在可以通过index直接访问任意一个元素，而链表不行。由于二分查找法每次需要找到中点，而链表的查找中间点可以通过快慢指针来操作，可参见之前的两篇博客Reorder List 链表重排序和Linked List Cycle II 单链表中的环之二有关快慢指针的应用。找到中点后，要以中点的值建立一个数的根节点，然后需要把原链表断开，分为前后两个链表，都不能包含原中节点，然后再分别对这两个链表递归调用原函数，分别连上左右子节点即可。代码如下： 
*/
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (!head) return NULL;
		if (!head->next) return new TreeNode(head->val);
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *last = slow;
		while (fast->next && fast->next->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		last->next = NULL;
		TreeNode *cur = new TreeNode(slow->val);
		if (head != slow) cur->left = sortedListToBST(head);
		cur->right = sortedListToBST(fast);
		return cur;
	}
}
