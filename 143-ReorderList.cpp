//Reorder List 链表重排序
/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

//看懂题意 题目规定要in-place，也就是说只能使用O(1)的空间
//可以找到中间节点，断开，把后半截单链表reverse一下，再合并两个单链表
//时间复杂度n 空间复杂度1
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return;
		ListNode *slow = head, *fast = head, *prev = NULL;
		
		//找到链表中间节点的方法双指针 s步 2s步 （精辟）
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		
		prev->next = NULL;  	//中间节点减掉

		slow = reverse(slow);  	//头插法翻转链表 （精辟）

		//合并两个链表
		ListNode *curr = head;
		while (curr->next) {
			ListNode *tmp = curr->next;
			curr->next = slow;
			slow = slow->next;
			curr->next->next = tmp;
			curr = tmp;
		}
		curr->next = slow;
	}

	//头插法翻转链表
	ListNode* reverse(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode *prev = head;
		for (ListNode *curr = head->next, *next = curr->next; curr;) {		
			curr->next = prev;
			prev = curr;
			curr = next;
			next = next ? next->next : NULL;
		}
		head->next = NULL;
		return prev;
	}
};
