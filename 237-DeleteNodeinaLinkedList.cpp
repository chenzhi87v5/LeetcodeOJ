//Delete Node in a Linked List 删除链表的节点

/*Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should 
become 1 -> 2 -> 4 after calling your function.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//在链表中删除一个节点，只给出这个节点的访问
//不要想的太复杂了 将下一个节点的值赋值给本节点， 删除下一节点
class Solution {
public:
	void deleteNode(ListNode* node) {
		if (node == NULL || node->next == NULL)
			return;
		ListNode *next = node->next;
		node->val = next->val;
		node->next = next->next;
		delete next;
		next = NULL;
		return;
	}
};

//注意考虑特殊情况， 删除最后一个节点， 删除头节点， 删除中间节点（特殊情况就必须给定指定的head头结点）
