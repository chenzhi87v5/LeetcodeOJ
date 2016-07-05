//Merge Two Sorted Lists 混合插入有序链表
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
/*
这道混合插入有序链表和我之前那篇混合插入有序数组非常的相似，仅仅是数据结构由数组换成了链表而已，代码写起来反而更简洁。具体思想就是新建一个链表，然后比较两个链表中的元素值，把较小的那个链到新链表中，由于两个输入链表的长度可能不同，所以最终会有一个链表先完成插入所有元素，则直接另一个未完成的链表直接链入新链表的末尾。代码如下： 
*/
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
