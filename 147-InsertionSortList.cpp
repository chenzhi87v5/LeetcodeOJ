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

//1-:插入排序链表 思考好逻辑关系
//时间复杂度n^2 空间复杂度 1
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
