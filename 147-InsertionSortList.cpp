//Insertion Sort List 链表插入排序
/*
Sort a linked list using insertion sort. 
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
链表的插入排序实现原理很简单，就是一个元素一个元素的从原链表中取出来，然后按顺序插入到新链表中，时间复杂度为O(n2)，
是一种效率并不是很高的算法，但是空间复杂度为O(1)，以高时间复杂度换取了低空间复杂度。代码如下： 
*/
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(INT_MIN);

		for (ListNode *cur = head; cur != NULL;) {
			auto pos = findInsertPos(&dummy, cur->val);
			ListNode *tmp = cur->next;
			cur->next = pos->next;
			pos->next = cur;
			cur = tmp;
		}
		return dummy.next;
	}

	//寻找插入位置
	ListNode* findInsertPos(ListNode *head, int x) {
		ListNode *pre = NULL;
		for (ListNode *cur = head; cur != NULL && cur->val <= x;) {
			pre = cur;
			cur = cur->next;
		}

		return pre;
	}
};
//代码借鉴版
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode *res = new ListNode(-1);
		ListNode *cur = res;
		while (head) {
			ListNode *next = head->next;
			cur = res;
			while (cur->next && cur->next->val <= head->val) {
				cur = cur->next;
			}
			head->next = cur->next;
			cur->next = head;
			head = next;
		}
		return res->next;
	}
}
