//Odd Even Linked List 奇偶链表
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about 
the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:

Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...
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
两个奇偶指针分别指向奇偶节点的起始位置，另外需要一个单独的指针even_head来保存偶节点的起点位置，然后把奇节点的指向偶节点的下
一个(一定是奇节点)，此奇节点后移一步，再把偶节点指向下一个奇节点的下一个(一定是偶节点)，此偶节点后移一步，以此类推直至末尾
，此时把分开的偶节点的链表连在奇节点的链表后即可，参见代码如下； 
*/
//简单 注意细节实现
//odd 奇  even 偶
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *odd = head, *even = head->next, *even_head = even;
		while (even && even->next) {
			odd = odd->next = even->next;
			even = even->next = odd->next;
		}
		odd->next = even_head;
		return head;
	}
};
