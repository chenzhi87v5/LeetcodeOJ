//Remove Duplicates from Sorted List II 移除有序链表中的重复项之二
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*和之前那道不同的地方是这里要删掉所有的重复项*/
//区别一下: 递归版（另起函数类似dfs） 与 迭代版（类似本函数处理完）
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode dummy(INT_MAX); //头结点
		dummy.next = head;
		ListNode *prev = &dummy, *cur = head;
		
		while (cur != NULL) {
			bool duplicated = false;
			while (cur->next != NULL && cur->val == cur->next->val) {
				duplicated = true;
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
			}
			if (duplicated) {         //删除重复的元素
				ListNode *temp = cur;
				cur = cur->next;
				delete temp;
				continue;
			}
			prev->next = cur;
			prev = prev->next;
			cur = cur->next;
		}
		prev->next = cur;
		return dummy.next;
	}
};
