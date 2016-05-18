/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

//头插法实现链表翻转

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *prev = NULL; //新的链表头
		while (head != NULL) {
			ListNode *temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}

		return prev;
	}
};
