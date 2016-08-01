//Remove Duplicates from Sorted List 移除有序链表中的重复项
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

/*
移除有序链表中的重复项需要定义个指针指向该链表的第一个元素，然后第一个元素和第二个元素比较，如果重复了，则删掉第二个元素，
如果不重复，指针指向第二个元素。这样遍历完整个链表，则剩下的元素没有重复项。代码如下： 
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		
		ListNode *start = head;
		while (start && start->next) {
			if (start->val == start->next->val) {
				ListNode *tmp = start->next;
				start->next = start->next->next;
				delete tmp;
			} else {
				start = start->next;
			}
		}
		return head;
	}
};
