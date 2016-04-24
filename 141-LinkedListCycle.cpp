/*
Given a linked list, determine if it has a cycle in it.

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
1.最容易想到的方法是，用一个哈希表unordered_map<int, bool> visited，记录每个元素是
  否被访问过，一旦出现某个元素被重复访问，说明存在环。空间复杂度O(n)，时间复杂度O(N)。

2.最好的方法是时间复杂度O(n)，空间复杂度O(1) 的。设置两个指针，一个快一个慢，快
  的指针每次走两步， 慢的指针每次走一步， 如果快指针和慢指针相遇， 则说明有环。
*/

class Solution {
public:
	bool hasCycle(ListNode *head) {
		//设置两个指针，一个快，一个慢  相遇有环 不相遇无环
		ListNode *slow = head;
		ListNode *fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}

		return false;
	}
};
