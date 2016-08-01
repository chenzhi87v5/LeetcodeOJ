//Rotate List 旋转链表
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

//形成环,向后跑len-k步
/*
先遍历整个链表获得链表长度n，然后此时把链表头和尾链接起来，在往后走n - k % n个节点就到达新链表的头结点前一个点，
这时断开链表即可，代码如下: 
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL|| k == 0 )
			return head;

		int len = 1;
		ListNode *p = head;
		while (p->next) { 	//求链表长度
			len++;
			p = p->next;
		}

		k = len - k % len;
		if(k == len)   		//不需要旋转
			return head;

		p->next = head; 	//首尾想连
		for (int step = 0; step < k; step++)
			p = p->next; 	//接着往后跑
		head = p->next;  	//新的首节点
		p->next = NULL;   	// 断开环
		return head;	
	}
};
