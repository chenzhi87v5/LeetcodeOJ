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
这道题是要求把有序链表转为二叉搜索树，和之前那道Convert Sorted Array to Binary Search Tree 将有序数组转为二叉搜索树思路
完全一样，只不过是操作的数据类型有所差别，一个是数组，一个是链表。数组方便就方便在可以通过index直接访问任意一个元素，而
链表不行。由于二分查找法每次需要找到中点，而链表的查找中间点可以通过快慢指针来操作，可参见之前的两篇博客Reorder List 链表
重排序和Linked List Cycle II 单链表中的环之二有关快慢指针的应用。找到中点后，要以中点的值建立一个数的根节点，然后需要把原链
表断开，分为前后两个链表，都不能包含原中节点，然后再分别对这两个链表递归调用原函数，分别连上左右子节点即可。代码如下： 
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
		
		if (head != slow) cur->left = sortedListToBST(head);    //关键点 if (head != slow) 考虐链表两个节点情况
		cur->right = sortedListToBST(fast);
		return cur;
	}
}
