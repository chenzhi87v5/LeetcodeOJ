//Sort List 链表排序   归并排序
/*
Sort a linked list in O(nlogn) time using constant space complexity. 
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
常见排序方法有很多，
	冒泡排序，
	插入排序，
	选择排序，
	归并排序，
	快速排序，
	归并排序，
	堆排序，
	桶排序等等。。
它们的时间复杂度不尽相同，而这里题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序，而根据单链表的特点，最适于用归并排序。代码如下： 
*/
//链表排序 要求时间复杂度nlogn  空间复杂度是1
//常数空间且O(nlogn)，单链表适合用归并排序，双向链表适合用快速排序
//本题可以复用”Merge Two Sorted Lists” 的代码
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		//快慢指针找到中间节点
		ListNode *fast = head, *slow = head;
		while(fast->next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}

		//断开
		fast = slow;
		slow = slow->next;
		fast->next = NULL;

		ListNode *l1 = sortList(head);  //前半段排序
		ListNode *l2 = sortList(slow);  //后半段排序
		return mergeTwoLists(l1, l2);
	}

	//合并两个排序链表
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(-1);

		for (ListNode *p = &dummy; l1 != NULL || l2 != NULL; p = p->next) {
			//（精辟）
			int val1 = l1 == NULL ? INT_MAX : l1->val;
			int val2 = l2 == NULL ? INT_MAX : l2->val;
			
			if (val1 <= val2) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
		}
		return dummy.next;
	}
};
