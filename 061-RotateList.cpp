/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */

//1-:双指针 代码冗余
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode dummy(-1);
		dummy.next = head;
		
		if (head == NULL || head->next == NULL || k == 0)  //判断是否需要旋转
			return dummy.next;

		ListNode *p = head, *q;
		int n = 1;
		while (p->next != NULL) {   //计算链表长度
			p = p->next;
			n++;
		}
		
		k = k % n;
		if (k == 0)        // 判断是否需要旋转
			return dummy.next;

		p = head;
		q = head;
		while (k--) {
			q = q->next;
		}

		while (q->next != NULL) {
			p = p->next;
			q = q->next;
		}
		dummy.next = p->next;
		p->next = NULL;
		q->next = head;

		return dummy.next;
	}
};

//2-形成环,向后跑len-k步
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || k == 0)
			return head;

		int len = 1;
		ListNode *p = head;
		while (p->next) { //求链表长度
			len++;
			p = p->next;
		}

		k = len - k % len;
		if(k == len)   //不需要旋转
			return head;

		p->next = head; //首尾想连
		for (int step = 0; step < k; step++)
			p = p->next; //接着往后跑
		head = p->next;  //新的首节点
		p->next = NULL;   // 断开环
		return head;	
	}
};
