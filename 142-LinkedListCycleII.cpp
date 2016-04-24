/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
 利用数学计算
 从链表头到环入口点等于n - 1 圈内环+ 相遇点到环入口点，
 于是我们可以从head 开始另设一个指针slow2，两个慢指针每次前进一步，它俩
 一定会在环入口点相遇。
 */

//时间复杂度n 空间复杂度 1
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {    //相遇点 再起一个slow2 依次向后移动必在环入口相遇
				ListNode *slow2 = head;
				while (slow2 != slow) {
					slow2 = slow2->next;
					slow = slow->next;
				}
				return slow2;
			}
		}

		return NULL;
	}
};
