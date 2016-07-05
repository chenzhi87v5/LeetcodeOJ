//Linked List Cycle II 单链表中的环之二
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
 这个求单链表中的环的起始点是之前那个判断单链表中是否有环的延伸. 还是要设快慢指针，不过这次要记录两个指针相遇的位置，当两个指针相遇了后，让其一指针从链表头开始，此时再相遇的位置就是链表中环的起始位置。代码如下：
 */

//时间复杂度n 空间复杂度1
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
}
