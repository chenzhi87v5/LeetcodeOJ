//Remove Nth Node From End of List 移除链表倒数第N个节点
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//(只需要扫描一遍)使用两个指针,前一个先走n步
// new delete 的使用： ListNode *res = new ListNode(0);  delete res
//1. 考虑异常 空指针 2.链表长度不足N  3.移除头指针  参数检测防御性编程
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *p = &dummy, *q = &dummy;

		for (int i = 0; i < n; i++)
			q = q->next;

		while (q ->next) { //一起走
			p = p->next;
			q = q->next;
		}
		ListNode *tmp = p->next;
		p->next = p->next->next;
		delete tmp;          //防止内存泄漏
		return dummy.next;
	}
};
