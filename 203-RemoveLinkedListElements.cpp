//Remove Linked List Elements 移除链表元素
/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
这道移除链表元素是链表的基本操作之一，没有太大的难度，就是考察了基本的链表遍历和设置指针的知识点，我们只需定义几个辅助指针，然后遍历原链表，遇到与给定值相同的元素，将该元素的前后连个节点连接起来，然后删除该元素即可，要注意的是还是需要在链表开头加上一个dummy node，具体实现参见代码如下： 
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(-1);
		dummy.next = head;
		head = &dummy;
		
		while (head->next != NULL) {
			if (head->next->val == val) {
				ListNode *tmp = head->next;
				head->next = head->next->next;
				delete tmp;
			} else {
				head = head->next;
			}
		}
	
		return dummy.next;
	}
};
