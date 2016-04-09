/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */


/*1-mySolution*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next ==NULL)
			return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy, *r = head, *l = head->next;
		do {
			ListNode *tem = l->next;
			p->next = l;
			l->next = r;
			r->next = tem;
			if (r->next == NULL || r->next->next == NULL)
				break;
			p = p->next->next;
			r = r->next;
			l = l->next->next->next;
		
		} while (1);

		return dummy.next;
	}
};

