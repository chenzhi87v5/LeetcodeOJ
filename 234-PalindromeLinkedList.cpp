//Palindrome Linked List 回文链表

/*Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//法一 遍历一遍存储到vector，前后夹逼对比判断是否是回文
class Solution {
public:
	bool isPalindrome(ListNode* head) {		            
		if (head == NULL) {
			return true;
		}
		vector<int> v;
		while(head) {
			v.push_back(head->val);
			head = head->next;
		}
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
			if (v[i] != v[j])
				return false;
		}
		return true;
	}
};

/*这道题的Follow Up让我们用O(1)的空间，那就是说我们不能使用stack了，那么如果代替stack的作用呢，用stack的目的是为了利用其后进
先出的特点，好倒着取出前半段的元素。那么现在我们不用stack了，如何倒着取元素呢。我们可以在找到中点后，将后半段的链表翻转一
下，这样我们就可以按照回文的顺序比较了，参见代码如下： */
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode *slow = head, *fast = head;
		
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *last = slow->next, *pre = head;
		
		while (last->next) {
			ListNode *tmp = last->next;
			last->next = tmp->next;
			tmp->next = slow->next;
			slow->next = tmp;
		}
		while (slow->next) {
			slow = slow->next;
			if (pre->val != slow->val) return false;
			pre = pre->next;
		}

		return true;
	}
}
