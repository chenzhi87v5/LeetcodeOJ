/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

//1-:时间复杂度n ,使用双指针 删除重复的元素

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode dummy(-1);
		dummy.next = head;
		if (head == NULL || head->next == NULL) //如果为空或者一个节点直接返回
			return dummy.next;

		ListNode *p = head, *q = head->next;   
		while (q != NULL) {
			if (q->val == p->val) {       //重复节点忽略，并且删除防止内存泄露
				ListNode *t = q;
				q = q->next;
				delete t;

			} else {                       //非重复节点q 直接添加到p节点后
				p->next = q;
				p = q;
				q = q->next;
			} 
		}
		p ->next = NULL;

		return dummy.next;
	}
};
