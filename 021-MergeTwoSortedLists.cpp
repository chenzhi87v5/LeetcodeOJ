/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists. 
*/

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

/*1-mySolution:*/
/*
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode *p = &dummy, *p1 = l1, *p2 = l2;
		while (p1 != NULL || p2 != NULL) {
			if (p1 == NULL && p2 != NULL) {
				p->next = p2;
				break;
			} else if (p2 == NULL && p1 != NULL) {
				p->next = p1;
				break;
			} else if (p1->val < p2->val) {
				p->next = p1;
				p = p->next;
				p1 = p1->next;
			} else {
				p->next = p2;
				p = p->next;
				p2 = p2->next;
			}
		}

		return dummy.next;
	}
};
*/
/*2-Answers:*/

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) 
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode dummy(-1);
		ListNode *p = &dummy;
		for (;l1 != NULL && l2 != NULL; p = p->next) {  // &&号
			if (l1->val > l2->val) {
				p->next = l2;
				l2 = l2->next;
			} else {
				p->next = l1;
				l1 = l1->next;
			}
		}
		p->next = l1 != NULL ? l1 : l2;   // 其中一个是否为空
		
		return dummy.next;
	}
};

